#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <map>
#include <set>
#include <vector>
#include </opt/homebrew/include/mysqlx/xdevapi.h>

using namespace mysqlx;
using namespace std;

int main(int argc, char *argv[]) {
    std::string query;
    map<std::string, set<std::string>> columnValues;

    if (argc > 1) {
        query = argv[1];
        for (int i = 2; i < argc; ++i) {
            query += " " + std::string(argv[i]);
        }
    } else {
        cerr << "Usage: " << argv[0] << " <SQL query>" << endl;
        return 1;
    }

    const char* dbUser = std::getenv("DB_USER");
    const char* dbPassword = std::getenv("DB_PASSWORD");

    try {
        Session session("localhost", 33060, dbUser, dbPassword);

        SqlResult result = session.sql(query).execute();

        const auto& cols = result.getColumns();
        int colCount = result.getColumnCount();

 // Print headers
        for (int i = 0; i < colCount; ++i) {
            cout << setw(20) << cols[i].getColumnName() << " | ";
            columnValues[cols[i].getColumnName()] = set<std::string>();
        }
        cout << endl;

        // rows
        std::string value;
        for (Row row : result) {
            for (int i = 0; i < colCount; ++i) {
                try {
                    cout << setw(20) << row[i] << " | ";
                    value =  (row[i].isNull() ) ? "NULL" : row[i].get<std::string>();
                    columnValues[cols[i].getColumnName()].insert(row[i]);
                } catch (const exception &e) {
                    cerr << "\n1 Error processing value '" << row[i] << "': " << e.what() << endl;
                }
            }
            cout << endl;
        }
        session.close();
        cout << "\nUnique values per column:" << endl;
        for (const auto& col : columnValues) {
            try {
            cout << col.first << ": " << col.second.size() << " unique values" << endl;
            } catch (const exception &e) {
                cerr << "\n2 Error processing column '" << col.first << "': " << e.what() << endl;
            }
        }
    }
    catch (const exception &e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }

    return 0;
}