#include <iostream>
#include <fstream>
#include <map>
#include <numeric>
#include <set>
#include <string>

// using namespace std;

//  NOTE: define a student struct to hold student data
struct student {
	std::string name;        //  NOTE: needs include <string> and eitiher std::string or using namespace std;
	int age;
	std::string zip;
    std::string	major;
};

int main () {
    //  NOTE: create a stident struct and a map to hold students by name
    student s;
    std::map <std::string, student> stMap;  // NOTE: needs include <map> and std::map or using namespace std;
    std::set <std::string> zips;            // NOTE: needs include <set> and std::vector or using namespace std;

    // NOTE: then read students from a file and store in the map
    std::ifstream ifs("lego.txt");          //  needs include <fstream> and std::ifstream or using namespace std;
    while (ifs >> s.name >> s.zip >> s.age >> std::quoted(s.major)) {
	    stMap[s.name] = s;
        //  needs include <iostream> and std::cout or using namespace std;
        std::cout << s.name << " " << s.zip << " " << s.age << " " << s.major << std::endl;
        zips.insert(s.zip);
    }
    ifs.close();

    //  NOTE: lookup a student by name
    std::string name;
    std::cout << "Enter student name: ";
    std::cin >> name;
    auto it = stMap.find(name);     //  this is the safe way to find a key in the map
                                    //  without creating a new entry if not found
    if (it != stMap.end()) {        //  this pattern finds the key
                                    //  the key was found, it->second is the student struct
        std::cout << "Found: " << it->second.name << " " << it->second.zip << " " << it->second.age << " " << it->second.major << std::endl;
    } else {
        std::cout << "Student not found\n";
    }

    std::cout << "Enter student name: ";
    std::cin >> name;
    s = stMap[name];        //  this will create a new student with default values if name not found
                            //  NOTE: the key is now created BUT the value ibject student is has not been initialized with data from the file, it is a default student with empty name and major and age 0
                             //  this is a common mistake when using maps, it creates a new entry if key not found
    std::cout << "Found: " << s.name << " " << s.zip << " " << s.age << " " << s.major << std::endl;

    // NOTE: create an output file and write all students to it
    std::ofstream ofs("students.out");          //  needs include <fstream> and std::ofstream or using namespace std;

    //  print all students
    std::cout << "\nAll students:\n";
    for (const auto& pair : stMap) {
        const student& s = pair.second;
        ofs << pair.first << " " << s.zip << " " << s.age << " " << s.major << std::endl;
        //  NOTE: the we use pair.first to show the key and NOT s.name because the key is the name
        //  and the value is the student struct which also has a name field but was never initialized
        std::cout << pair.first << " " << s.zip << " " << s.age << " " << s.major << std::endl;
    }
    ofs.close();

    // NOTE: print all unique zips from a set
    std::cout << "\nAll Zips:\n";
    for (const auto zip : zips) {
        std::cout << zip << std::endl;
    }

    //  NOTE: accumulate example - compute average age of students
    //  needs include <numeric>
    float aveAge = accumulate(stMap.begin(), stMap.end(), 0.0,
            [](double sum, const std::pair<std::string, student>& p)
                { return sum + p.second.age; }) / stMap.size();
    std::cout << "\nAverage age: " << aveAge << std::endl;
    return 0;
}