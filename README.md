# BOM - Simple Bookmark Manager

## Introduction

BOM is a command-line tool designed to manage bookmarks in a simple and efficient way. The tool allows users to add and manage bookmarks, storing them in a plaintext file using a straightforward standard format.

This project is a collaborative experiment, guided by the assistance of ChatGPT, an advanced AI developed by OpenAI. As someone who is not very experienced with C programming, I am leaning on ChatGPT to help build something useful while also learning and expanding knowledge in C.

BOM is currently in the early stages of development, and things can and will change. Contributions, feedback, and suggestions are welcome!

## Features

- **Add Bookmarks:** Prompted for the URL (required), title (optional), and tags (optional).
- **Simple Storage:** Bookmarks are stored in a plaintext file with a simple standard format, consisting of the URL, title, tags, and the date/time the bookmark was added.
- **Cross-Platform:** Initially developed for OSX with plans to support other platforms.

## Format

The standard format for storing bookmarks is as follows:

```
url
title
tags separated by commas
datetime
```

## Usage

Compile the program using:

```bash
gcc -Wall -o bom bom.c
```

Or use the provided Makefile:

```bash
make
```

Add a new bookmark:

```
./bom add
```

Follow the prompts to enter the URL, title, and tags.

## Contributing

Feel free to fork this repository, make changes, and submit pull requests. Any contributions to enhance the functionality or fix issues are appreciated.

## Disclaimer

This tool is part of a learning experiment and should be used with an understanding of its experimental nature. It may contain bugs, incomplete features, or other issues.
