#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include </opt/homebrew/include/mysqlx/xdevapi.h>

using namespace mysqlx;
using namespace std;

int main(int argc, char *argv[]) {
    std::string schema, table, columns;

    // Get database credentials from environment variables
    const char* dbUser = std::getenv("DB_USER");
    const char* dbPassword = std::getenv("DB_PASSWORD");

    try {
        // Connect to the MySQL server
        Session session("localhost", 33060, dbUser, dbPassword);
        
        // List all schemas in the server
        //  a schema is a set of tables that belong to the same application.
        std::vector<Schema> schemas = session.getSchemas();
        cout << "Schemas:" << endl;
        for (const auto& schema : schemas) {
            std::string dbName = schema.getName();
            cout << " - " << dbName << endl;
        }

        //  If a schema name is provided as a command-line argument, 
        //      list all tables in the schema
        for (int i = 1; i < argc; ++i) {
            std::string dbName = argv[i];
            Schema db = session.getSchema(dbName);

            vector<std::string> tableNames = db.getTableNames();
            cout << "Tables in schema '" << dbName << "':" << endl;
            for (const std::string& name : tableNames) {
                cout << " - " << name << endl;
            }
        }

        //  If no schema name is provided as a command-line argument, prompt the user for input
        cout << "Enter schema and table name to get column attributes: ";
        cin >> schema >> table;
        if (schema.empty() || table.empty()) {
            cerr << "Schema and table names cannot be empty." << endl;
            return 1;
        }

        SqlResult result = session
            .sql("SELECT COLUMN_NAME, COLUMN_TYPE, COLUMN_KEY, IS_NULLABLE, COLUMN_DEFAULT, EXTRA "
                 "FROM INFORMATION_SCHEMA.COLUMNS "
                 "WHERE TABLE_SCHEMA = ? AND TABLE_NAME = ? "
                 "ORDER BY COLUMN_KEY desc, COLUMN_NAME")       //  ORDINAL_POSITION
            .bind(schema)
            .bind(table)
            .execute();

        cout << "Column attributes for " << schema << "." << table << ":" << endl;
        cout << "       name          |     type      | key  |" << endl;    // nullable |  default |  extra";

        for (Row row : result) {
            cout << left 
                 << setw(20) << row[0] << " | " << right
                 << setw(13) << row[1] << " | "
                 << setw(4)  << row[2] << " | "
                //  << setw(8)  << row[3] << " | "
                //  << setw(8)  << row[4] << " | "
                //  << setw(8)  << row[5]
                 << endl;
        }
        cin.ignore(); // Clear the newline character from the input buffer
        cout << "Selected columns (col1, col2, ...): " << endl;
        getline(cin, columns);
        if (! columns.empty()) {
            cout << "SELECT " + columns + " FROM " + schema + "." + table << endl;
            RowResult result = session.sql("SELECT " + columns + 
                                            " FROM " + schema + "." + table +
                                            " Order By 1")
                    .execute();
            int colCount = result.getColumnCount();
            for (Row row : result) {
                for (int i = 0; i < colCount; ++i) {
                    cout << setw(20) << row[i] << " | ";
                }
                cout << endl;
            }
        }

        session.close();
    }
    catch (const exception &e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }
    
    return 0;
}