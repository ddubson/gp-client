### Pre-requisites

- [cmake 3.13+](https://cmake.org/)
- libpq
- libpqxx

### Compiling

```bash
./compile.sh
```

Creates `cmake-build-debug` with Makefile and other files.

### Running

Compile the project first and then:

```bash
export GP_HOST=
export GP_PORT=
export GP_DB_NAME=
export GP_DB_USER=
export GP_DB_PASS=

./cmake-build-debug/gp_client $GP_HOST $GP_PORT $GP_DB_NAME $GP_DB_USER $GP_DB_PASS
```