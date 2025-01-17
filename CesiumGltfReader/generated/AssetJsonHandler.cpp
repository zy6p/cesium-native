// This file was generated by generate-gltf-classes.
// DO NOT EDIT THIS FILE!
#include "AssetJsonHandler.h"
#include "CesiumGltf/Asset.h"

#include <cassert>
#include <string>

using namespace CesiumGltf;

AssetJsonHandler::AssetJsonHandler(const ReaderContext& context) noexcept
    : ExtensibleObjectJsonHandler(context),
      _copyright(),
      _generator(),
      _version(),
      _minVersion() {}

void AssetJsonHandler::reset(
    CesiumJsonReader::IJsonHandler* pParentHandler,
    Asset* pObject) {
  ExtensibleObjectJsonHandler::reset(pParentHandler, pObject);
  this->_pObject = pObject;
}

CesiumJsonReader::IJsonHandler*
AssetJsonHandler::readObjectKey(const std::string_view& str) {
  assert(this->_pObject);
  return this->readObjectKeyAsset(Asset::TypeName, str, *this->_pObject);
}

CesiumJsonReader::IJsonHandler* AssetJsonHandler::readObjectKeyAsset(
    const std::string& objectType,
    const std::string_view& str,
    Asset& o) {
  using namespace std::string_literals;

  if ("copyright"s == str)
    return property("copyright", this->_copyright, o.copyright);
  if ("generator"s == str)
    return property("generator", this->_generator, o.generator);
  if ("version"s == str)
    return property("version", this->_version, o.version);
  if ("minVersion"s == str)
    return property("minVersion", this->_minVersion, o.minVersion);

  return this->readObjectKeyExtensibleObject(objectType, str, *this->_pObject);
}
