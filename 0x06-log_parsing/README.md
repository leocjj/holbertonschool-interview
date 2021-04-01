# Project 0x03. Log Parsing

## Requirementes - General

    Allowed editors: vi, vim, emacs
    All your files will be interpreted/compiled on Ubuntu 14.04 LTS using python3 (version 3.4.3)
    All your files should end with a new line
    The first line of all your files should be exactly #!/usr/bin/python3
    A README.md file, at the root of the folder of the project, is mandatory
    Your code should be documented
    Your code should use the PEP 8 style (version 1.7.x)
    All your files must be executable


## 0. Minimum Operations
Write a script that reads stdin line by line and computes metrics:

    Input format: <IP Address> - [<date>] "GET /projects/260 HTTP/1.1" <status code> <file size>
    After every 10 lines and/or a keyboard interruption (CTRL + C), print these statistics from the beginning:
        Total file size: File size: <total size>
        where <total size> is the sum of all previous <file size> (see input format above)
        Number of lines by status code:
            possible status code: 200, 301, 400, 401, 403, 404, 405 and 500
            if a status code doesn’t appear, don’t print anything for this status code
            format: <status code>: <number>
            status codes should be printed in ascending order

## Built With

* Windows 10
* Python 3.6
* Pycharm 2020.2
* Pycharm style

## Author

**Leonardo Calderon J.** - *Initial work* 

## [LeoCJJ](https://github.com/leocjj)

[Web Page](http://leocjj.tech)

2021
