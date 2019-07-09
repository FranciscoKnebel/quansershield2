# Quanser Shield v.2

Intel Galileo Gen 2 shield for use with the Quanser 2DSFJE robot.
Documentation can be found in the `docs/` folder or by accessing the link [https://franciscoknebel.github.io/quansershield2/](https://franciscoknebel.github.io/quansershield2/).

## Prerequisites
- Doxygen
```
  $ sudo apt install doxygen
```

- GCC
- Make

## File Hierarchy
- bin
  - Temporary folder for built program binaries.
- docs
  - Project documentation, built with Doxygen.
- ext
  - External files, used in documentation.
- include
  - Header Files.
- init
  - Intel Galileo `/etc/init.d` files to setup pins.
- lib
  - Folder for storage of built library files.
- scripts
  - Scripts used to automate project tasks.
- src
  - Project source files.

## Makefile

### Project
- Compile the full project with `make`.
- Clean built files with `make clean`.

Don't forget to setup environment variables from `iss_setup.sh`;

### Documentation
Compile the project documentation to `docs/` folder.
```
  $ doxygen
```

Then you can open the `docs/index.html` file and search the `Files` section for code documentation.
To change the docs generation configuration, you need to install the `doxygen-gui` config and run:
```
  $ doxywizard Doxyfile
```

## Versioning

We use [SemVer](http://semver.org/) for versioning. For the versions available, see the [tags on this repository](https://github.com/FranciscoKnebel/quansershield2/tags).

## Authors

<table style="text-align: center;">
  <tr>
    <th>Contributors</th>
    <th>Contributions</th>
  </tr>
  <tr>
    <td>
      <img src="https://avatars.githubusercontent.com/FranciscoKnebel?s=75">
      <br>
      <a href="https://github.com/FranciscoKnebel">Francisco Knebel</a>
    </td>
    <td>
      <a href="https://github.com/FranciscoKnebel/quansershield2/commits?author=FranciscoKnebel">Contributions</a> by FranciscoKnebel
    </td>
  </tr>
  <tr>
    <td>
      <img src="https://avatars.githubusercontent.com/lzancan?s=75">
      <br>
      <a href="https://github.com/lzancan">Luciano Zancan Mazzutti</a>
    </td>
    <td>
      <a href="https://github.com/FranciscoKnebel/quansershield2/commits?author=lzancan">Contributions</a> by lzancan
    </td>
  </tr>
  <tr>
    <td>
      <img src="https://avatars.githubusercontent.com/rodrigodalri?s=75">
      <br>
      <a href="https://github.com/rodrigodalri">Rodrigo Dal Ri</a>
    </td>
    <td>
      <a href="https://github.com/FranciscoKnebel/quansershield2/commits?author=rodrigodalri">Contributions</a> by rodrigodalri
    </td>
  </tr>
</table>

See also the full list of [contributors](https://github.com/FranciscoKnebel/quansershield2/contributors) who participated in this project.

## License

This project is licensed under the _GNU GENERAL PUBLIC LICENSE_ - see the [LICENSE.md](LICENSE.md) file for details.
