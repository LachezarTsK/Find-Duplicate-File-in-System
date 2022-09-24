
/**
 * @param {string[]} paths
 * @return {string[][]}
 */
var findDuplicate = function (paths) {

    const fileNameToPaths = new Map();//Map<string, string[]>

    for (let path of paths) {

        const currentPath = path.split(" ");
        
        for (let i = 1; i < currentPath.length; ++i) {

            let startIndexFileName = currentPath[i].lastIndexOf('(') + 1;
            let endIndexFileName = currentPath[i].lastIndexOf(')') - 1;
            let fileName = currentPath[i].substring(startIndexFileName, endIndexFileName + 1);

            if (!fileNameToPaths.has(fileName)) {
                fileNameToPaths.set(fileName, []);
            }
            fileNameToPaths.get(fileName).push(currentPath[0] + "/" + currentPath[i].substring(0, startIndexFileName - 1));
        }
    }

    const pathsToDuplicateFiles = [];
    for (let pathsForFile of fileNameToPaths.values()) {
        if (pathsForFile.length > 1) {
            pathsToDuplicateFiles.push(pathsForFile);
        }
    }

    return pathsToDuplicateFiles;
};
