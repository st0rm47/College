# Lab Report 21: CLI Commands in Shell

Command Line Interface (CLI) commands are used to interact with the .NET SDK and manage .NET projects. The .NET CLI provides a set of commands that allow developers to create, build, run, and manage .NET applications from the command line. Using CLI commands can streamline the development process and automate various tasks.

## dotnet --info
- This command displays detailed information about the .NET SDKs and runtimes installed on your machine.
- It includes version numbers, installation paths, and other relevant details.

## dotnet new list
- This command lists all the available project templates that you can use to create new .NET projects.
- It shows the template names, short names, languages, and tags associated with each template.

## dotnet new console -o MyApp
- This command creates a new .NET console application in a directory named "MyApp".
- The `-o` option specifies the output directory for the new project.

## cd MyApp
- This command changes the current directory to "MyApp", where the newly created console application resides.

## dotnet add package Dopper
- This command adds the "Dopper" NuGet package to the project.
- NuGet packages are libraries or tools that can be used in .NET projects to extend functionality.

## dotnet restore
- This command restores the dependencies and tools of a .NET project.
- It downloads and installs any missing NuGet packages specified in the project file.

## dotnet build
- This command compiles the .NET project and generates the necessary binaries.
- It checks for errors and warnings in the code and produces an executable or library.

## dotnet clean
- This command cleans the output of the previous build by deleting the compiled binaries and intermediate files.
- It is useful for ensuring a fresh build without any leftover artifacts.

## dotnet run
- This command builds and runs the .NET application in one step.
- It compiles the code (if necessary) and executes the resulting application.


