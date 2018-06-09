# Trabajo Práctico 2: Diseño, Implementación y Análisis C++

## Instalacion

Los siguientes requerimientos son necesarios

### Descarga del codigo fuente

#### Via ssh keys

```bash
$ git clone git@github.com:cristiandouce/tp2-algo2.git
# cloning repository to ./tp2-algo2
```

> Requiere cuenta en [GitHub](https://github.com/)

#### Via https

```bash
$ git clone https://github.com/ruso86/tp2-algo2
# cloning repository to ./tp2-algo2
```

> Requiere cuenta en [GitHub](https://github.com/)

#### Zip file

- [Descargar ZIP file](https://github.com/ruso86/tp2-algo2/archive/master.zip)

## Compilacion

```bash
g++ ./main.cpp -o ./bin/tp2
```

## Uso

```bash
$ ./bin/tp2 -h
> tp2 [-m method=DFT] [-i file=ISTREAM] [-o file=OSTREAM]
$
$ ./bin/tp2 -i ./test/ones.input.txt -o ./test/ones.output.txt
> # Procesa desde archivo  entrada e imprime a archivo salida
>
$ ./bin/tp2 -i ./test/ones.input.txt
> # Procesa archivo e imprime a ostream
>
$ ./bin/tp2 -o ./test/ones.output.txt
> # Procesa iostream e imprime en archivo salida
> # luego de encontrar [ctrl + D] (EOF)
>
$ ./bin/tp2 -m IDFT
> # Marca modo como IDFT
```

## Links

### VSCode

- [VS Code: C++ Development With Visual Studio Code](https://www.youtube.com/watch?v=X7CXjKGi_ro)
