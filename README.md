# BOM - Bookmark Manager CLI Tool

BOM is a simple command-line bookmark manager tool written in C. It stores bookmarks in a plaintext file using a simple standard format. This project is an experiment leaning on Chat GPT's guidance to build something useful, as the author is not very experienced with C.

## Features

- **Add bookmarks**: Easily add bookmarks with a URL, optional title, optional tags, and the date added.
- **List bookmarks**: View all bookmarks with beautiful colored formatting.
- **Simple plaintext storage**: Bookmarks are stored in a straightforward text file, using symbols to define different parts:
    - First line: URL (required)
    - Second line: Title (optional, wrapped in `[]`)
    - Third line: Tags (optional, comma-separated, starting with `#`)
    - Fourth line: Date added (optional, starting with `@`)

## Usage

Compile the program using:

```
make
```

Run the program with the desired command, such as:

```
./bom add
./bom list
```

## Future Goals

    Cross-platform support.
    Further improvements in UI/UX.
    More features and functionalities, such as editing or deleting bookmarks.

## Notes

This project is in its early stages, and things can and will change. Contributions, suggestions, and feedback are welcome!
Disclaimer

## Disclaimer

This README documents ongoing development, and the actual functionality may vary. Check the source code for the most accurate information.