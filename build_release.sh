if grep -q "THEOS_PACKAGE_SCHEME" Makefile; then
    sed -i '' '/THEOS_PACKAGE_SCHEME/d' Makefile
    echo "Removed 'THEOS_PACKAGE_SCHEME' from Makefile"
fi

if grep -q "THEOS_DEVICE_IP" Makefile; then
    sed -i '' '/THEOS_DEVICE_IP/d' Makefile
    echo "Removed 'THEOS_DEVICE_IP' from Makefile"
fi

rm -rf ./packages

echo "Building sideloaded version"
make clean > /dev/null
make clean package FINALPACKAGE=1 JAILED=1 > /dev/null

JAILED_DEB_FILE=$(find ./packages -name "*.deb" -type f)

if [ -n "$JAILED_DEB_FILE" ]; then
    NEW_NAME="${JAILED_DEB_FILE%.deb}_jailed.deb"
    mv "$JAILED_DEB_FILE" "$NEW_NAME"
    echo "Renamed: $JAILED_DEB_FILE to $NEW_NAME"
else
    echo "Warning: No .deb file found to rename"
fi

echo "Building rootful package"
make clean > /dev/null
make clean package FINALPACKAGE=1 > /dev/null

echo "Building rootless package"
make clean > /dev/null
make clean package FINALPACKAGE=1 THEOS_PACKAGE_SCHEME=rootless > /dev/null

./build_ipa.sh

echo "Finished building packages"
exit 0