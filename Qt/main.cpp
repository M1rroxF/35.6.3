#include <iostream>
#include <filesystem>
#include <vector>

using namespace std;
namespace fs = filesystem;


auto recursiveGetFileNamesByExtension =
       [](fs::path path,
          const std::string extension)
{
    vector<fs::path> vec;
    for(auto& p: fs::recursive_directory_iterator(path)) {
        if (!p.path().extension().compare(extension)) {
            vec.push_back(p.path());
        }
    }
    return vec;
};

int main()
{
    cout << "if you want to find a folder then enter \"empty\"" << endl;;
    for (int i = 0; i < 3; i++) {
        fs::path path;
        string extension;

        cout << "enter path: ";
        cin >> path;

        cout << "enter extension: ";
        cin >> extension;

        if (extension == "empty")
            extension = "";

        vector<fs::path> vec = recursiveGetFileNamesByExtension(path, extension);
        for (auto &i : vec) {
            cout << i.filename() << endl;
        }
    }
}
