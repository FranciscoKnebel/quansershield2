# Quanser Shield v.2

Intel Galileo Gen 2 shield for use with the Quanser 2DSFJE robot.

## Prerequisites
- Doxygen
```
  $ sudo apt install doxygen
```

- GCC
- Make

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

Then you can open the `docs/html/index.html` file and search the `Files` section for code documentation.
To change the docs generation configuration, you need to install the `doxygen-gui` config and run:
```
  $ doxywizard Doxyfile
```

## Versioning

We use [SemVer](http://semver.org/) for versioning. For the versions available, see the [tags on this repository](https://github.com/FranciscoKnebel/micros/tags).

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
      <a href="https://github.com/FranciscoKnebel/micros/commits?author=FranciscoKnebel">Contributions</a> by FranciscoKnebel
    </td>
  </tr>
  <tr>
    <td>
      <img src="https://avatars.githubusercontent.com/lzancan?s=75">
      <br>
      <a href="https://github.com/lzancan">Luciano Zancan</a>
    </td>
    <td>
      <a href="https://github.com/FranciscoKnebel/micros/commits?author=lzancan">Contributions</a> by lzancan
    </td>
  </tr>
  <tr>
    <td>
      <img src="https://avatars.githubusercontent.com/rodrigodalri?s=75">
      <br>
      <a href="https://github.com/rodrigodalri">Rodrigo Dal Ri</a>
    </td>
    <td>
      <a href="https://github.com/FranciscoKnebel/micros/commits?author=rodrigodalri">Contributions</a> by rodrigodalri
    </td>
  </tr>
</table>

See also the full list of [contributors](https://github.com/FranciscoKnebel/micros/contributors) who participated in this project.

## License

This project is licensed under the _GNU GENERAL PUBLIC LICENSE_ - see the [LICENSE.md](LICENSE.md) file for details.