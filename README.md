# DirectorySort
 
## Description
This application helps to automate the sorting of directories by files. 
Sometimes we transfer files of different formats into one folder, which spoils the aesthetic appearance and ease of use. Thanks to the application, such a folder will quickly sort all files by creating folders and moving files there to the appropriate format.

# Building

The project consists of a library responsible for sorting and all child objects, and a main file responsible for the main logic of using the application. \
Use: \
```cmake -S . -B build``` \
```cmake --build build ``` \
For building debug version*

# Use

```DirectorySort <"Directory for sorting">``` \
A file that describes the sorting structure will be created automatically the first time it is used. Also, if necessary, the library provides the ability to sort folders by a local configuration file in a sortable folder.

## Using a local file
Create a file in the sortable directory and name it ".ds_config.json"\
Structure of the configuration file: 
```
[
    [
        {
            "formats": [
                ".webp",
                ".png",
                ".jpeg",
                ".jpg"
            ]
        },
        {
            "exceptions": []
        },
        {
            "name_directory": "Images"
        }
    ],
    [
        {
            "formats": [
                ".mp4",
                ".wav"
            ]
        },
        {
            "exceptions": []
        },
        {
            "name_directory": "Videos"
        }
    ]
]
```
# Review

https://github.com/user-attachments/assets/2eb94523-d899-4bbf-b26e-3dfbb024bb24


