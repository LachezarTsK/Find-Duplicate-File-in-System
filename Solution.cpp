
#include <string>
#include <vector>
using namespace std;

class Solution {
    
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        
        unordered_map<string, vector < string>> fileNameToPaths;

        for (const auto& path : paths) {

            stringstream sstream(path);
            istream_iterator<string>begin(sstream);
            istream_iterator<string>end;
            vector<string> currentPath(begin, end);

            for (int i = 1; i < currentPath.size(); ++i) {

                int startIndexFileName = currentPath[i].find_last_of('(') + 1;
                int endIndexFileName = currentPath[i].find_last_of(')') - 1;
                string fileName = currentPath[i].substr(startIndexFileName, endIndexFileName - startIndexFileName + 1);

                fileNameToPaths[fileName].push_back(currentPath[0] + "/" + currentPath[i].substr(0, startIndexFileName - 1));
            }
        }

        vector<vector < string>> pathsToDuplicateFiles;
        for (const auto& [file, pathsForFile] : fileNameToPaths) {
            if (pathsForFile.size() > 1) {
                pathsToDuplicateFiles.push_back(pathsForFile);
            }
        }

        return pathsToDuplicateFiles;
    }
};
