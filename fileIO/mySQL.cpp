#include <string>
#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <algorithm>
#include </opt/homebrew/include/mysqlx/xdevapi.h>

using namespace std;
using namespace mysqlx;

struct Crime {
    std::string crimeId;        std::string complaintNum;    std::string fromDate;       std::string fromTime;
    std::string toDate;         std::string toTime;          std::string reportDate;     std::string keyCode;
    std::string offenseDesc;    std::string pdCode;          std::string description;    std::string categoryCode;
    std::string borough;        std::string location;        std::string premiseType;    std::string lawCatCode;
    double latitude;            double longitude;
};

//  g++ mySQL.cpp -o app -I/opt/homebrew/include -L/opt/homebrew/lib -lmysqlcppconnx
int main() {
    vector<Crime> crimes;

    try {
        Session session("localhost", 33060, "root", "!Anguilla76");

        Schema db = session.getSchema("examples");
        Table crimesTable = db.getTable("crimes");

        // RowResult result = db.sql("SELECT AVG(latitude) AS avgLat, AVG(longitude) AS avgLon FROM crimes").execute();

        RowResult result = crimesTable.select("borough", "offenseDesc", "locationOfOccurance", "premiseType")
                                // .orderBy("borough ASC")
                                .limit(1000)
                                .execute();

        Crime crime;
        for (mysqlx::Row row : result) {
            // crime.latitude = row[1].get<double>();
            // crime.longitude = row[2].get<double>();
            crime.borough     = row[0].get<std::string>();
            crime.offenseDesc = row[1].get<std::string>();
            crime.location    = row[2].get<std::string>();
            crime.premiseType = row[3].get<std::string>();
            crimes.push_back(crime);
        }
        // Prompt for output file
        std::string outputFile;
        cout << "Enter output file name: ";
        cin >> outputFile;

        ofstream outFile(outputFile);
        if (!outFile) {
            cout << "Error opening output file.\n";
            return 1;
        }

        for (const auto& crime : crimes) {
            outFile << setw(15) << right << crime.borough << " | "
                    << setw(15) << left << crime.location << " | "
                    << setw(35) << crime.offenseDesc << " | "
                    << setw(25) << crime.premiseType << endl;
        }
        outFile.close();

        std::string borough;
        cout << "Enter borough to count crimes: ";
        cin >> borough;
        auto count = count_if(crimes.begin(), crimes.end(), [borough](const Crime& c) {
            return c.borough == borough;
        });
        cout << "Number of crimes in " << borough << ": " << count << endl;
    }   
    catch (const mysqlx::Error &err) {
        cout << "Error: " << err << endl;
    }

    return 0;
}