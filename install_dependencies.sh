#!/bin/bash
set -e #abort with error if any command returns with something other than zero

############
# Install script for envire dependencies
# Run "$> sudo ./install_dependencies.sh" to install system wide
# Run "$> ./install_dependencies.sh <path_to_prefix>" to install to a local prefix
############

function build {
  git clone --branch $2 $1 $3
  mkdir $3/build
  cd $3/build
  cmake .. $4
  make -j4 install
  cd ../../
}

PREFIX=""
if [ "$#" -eq 1 ]; then
PREFIX="-DCMAKE_INSTALL_PREFIX=$1"

cat <<'EOF' > env.sh
export CMAKE_PREFIX_PATH=$1
export PKG_CONFIG_PATH=$1/lib/pkgconfig:$1/share/pkgconfig:$1/lib64/pkgconfig:$PKG_CONFIG_PATH
export LD_LIBRARY_PATH=$1/lib:$1/lib64:$LD_LIBRARY_PATH
export PATH=$1/bin:$PATH
EOF
source env.sh
  
fi


build https://github.com/rock-core/base-cmake.git master base-cmake "$PREFIX"
#SISL should be optional for base-types but it isn't
build https://github.com/SINTEF-Geometry/SISL.git master sisl "-DBUILD_SHARED_LIBS=ON $PREFIX"
build https://github.com/rock-core/base-logging.git master base-logging "$PREFIX"
build https://github.com/rock-core/base-types.git master base-types "-DBINDINGS_RUBY=OFF -DROCK_VIZ_ENABLED=FALSE $PREFIX"
build https://github.com/envire/base-numeric.git master base-numeric "$PREFIX"
build https://github.com/envire/base-boost_serialization.git master base-boost_serialization "$PREFIX"

#plugins
build https://github.com/envire/tools-plugin_manager.git master tools-plugin_manager "$PREFIX"




