
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Solution {

    public List<List<String>> findDuplicate(String[] paths) {

        Map<String, List<String>> fileNameToPaths = new HashMap<>();

        for (String path : paths) {

            String[] currentPath = path.split(" ");

            for (int i = 1; i < currentPath.length; ++i) {

                int startIndexFileName = currentPath[i].lastIndexOf('(') + 1;
                int endIndexFileName = currentPath[i].lastIndexOf(')') - 1;
                String fileName = currentPath[i].substring(startIndexFileName, endIndexFileName + 1);

                fileNameToPaths.putIfAbsent(fileName, new ArrayList<>());
                fileNameToPaths.get(fileName).add(currentPath[0] + "/" + currentPath[i].substring(0, startIndexFileName - 1));
            }
        }

        List<List<String>> pathsToDuplicateFiles = new ArrayList<>();
        for (List<String> pathsForFile : fileNameToPaths.values()) {
            if (pathsForFile.size() > 1) {
                pathsToDuplicateFiles.add(pathsForFile);
            }
        }

        return pathsToDuplicateFiles;
    }
}
