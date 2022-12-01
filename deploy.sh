#!/bin/sh

ROOT_PATH="/home/dev/autodeploy/"
ADYAX_DIR="codeadyax"
AQUIA_DIR="codeacquia"
ADYAX_BRANCH="develop"
AQUIA_BRANCH="develop"
ABSOLUTE_AQUIA_DIR=$ROOT_PATHAQUIA_DIR;
cd $ROOT_PATH
if [ "$(ls -A $ADYAX_DIR)" ]; then
  cd $ROOT_PATH$ADYAX_DIR  
  git pull origin $ADYAX_BRANCH
else
  git clone --branch $ADYAX_BRANCH git@code.adyax.com:Souriau/Souriau.git $ADYAX_DIR
fi

cd $ROOT_PATH$ADYAX_DIR
#rm -rf docroot/sites/all/modules/contrib/*
composer install

cd $ROOT_PATH$AQUIA_DIR
#rm -rf $ROOT_PATH$AQUIA_DIR/*

if [ "$(ls -A $AQUIA_DIR)" ]; then
  cd $ROOT_PATH$AQUIA_DIR  
  git pull origin $AQUIA_BRANCH
else
  git clone --branch $AQUIA_BRANCH souriau@svn-20497.prod.hosting.acquia.com:souriau.git $AQUIA_DIR
fi

cp -rf $ROOT_PATH$ADYAX_DIR/docroot $ROOT_PATH$AQUIA_DIR/docroot
cp -rf $ROOT_PATH$ADYAX_DIR/html $ROOT_PATH$AQUIA_DIR/html
cp -rf $ROOT_PATH$ADYAX_DIR/vendor $ROOT_PATH$AQUIA_DIR/vendor
cp -rf $ROOT_PATH$ADYAX_DIR/core_patches $ROOT_PATH$AQUIA_DIR/core_patches
cp -rf $ROOT_PATH$ADYAX_DIR/composer.* $ROOT_PATH$AQUIA_DIR

cd $ROOT_PATH$AQUIA_DIR/docroot
find . -name ".git" -type d -exec rm -rf {} \;
cd $ROOT_PATH$AQUIA_DIR
DATE=`date +"%Y-%m-%d %H:%M:%S"`
echo $DATE
git add .
git commit -m "AQUIA auto deploy "$ADYAX_BRANCH" "$DATE
git push origin $AQUIA_BRANCH