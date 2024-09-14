# Custom-Shell
###### Creating a custom shell in C++

## Downloading the repo:
###### Here are some ways to download the repo:

#### 1) Git clone
```bash
git clone "https://Calvyn-Van-Wyngaardt/Custom-Shell.git"
```
#### 2) Github CLI
```bash
gh repo clone Calvyn-Van-Wyngaardt/Custom-Shell
```
#### 3) Download the zip file manually
Navigate to https://github.com/Calvyn-Van-Wyngaardt/Custom-Shell and download the zip file

## Compiling & Clean-up
#### Compile:
```bash
make
```

#### Clean:
```bash
make clean
```

## Running the shell:
For now, this serves only as a proof of concept and will still need to be reworked to be an actual shell.
* To run the "shell":
    ```bash
    make run
    ```
* The first line requires the command to be executed,for example:
    ```bash
    ls
    ```
* The second line takes in the argument for the command:
    ```bash
    -la
    ```
* Which should yield something like this:
    ```bash
    Executing command: ls
    total 36
    drwxrwxrwx 1 pi pi  4096 Sep 14 18:28 .
    drwxrwxrwx 1 pi pi  4096 Sep 14 18:12 ..
    drwxrwxrwx 1 pi pi  4096 Sep 14 18:35 .git
    -rwxrwxrwx 1 pi pi    27 Sep 14 18:02 .gitignore
    -rwxrwxrwx 1 pi pi 35149 Sep 14 18:11 LICENSE
    -rwxrwxrwx 1 pi pi   432 Sep 14 18:39 README.md
    drwxrwxrwx 1 pi pi  4096 Sep 14 18:33 bin
    -rwxrwxrwx 1 pi pi   187 Sep 14 18:11 makefile
    drwxrwxrwx 1 pi pi  4096 Sep 14 18:11 src
    Command successfully executed! :D
    ```


###### Please note that this is still a work in progress and is far from completion
