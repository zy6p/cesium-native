// This file was generated by generate-gltf-classes.
// DO NOT EDIT THIS FILE!
#include "MaterialJsonHandler.h"
#include "CesiumGltf/Material.h"

#include <cassert>
#include <string>

using namespace CesiumGltf;

MaterialJsonHandler::MaterialJsonHandler(const ReaderContext& context) noexcept
    : NamedObjectJsonHandler(context),
      _pbrMetallicRoughness(context),
      _normalTexture(context),
      _occlusionTexture(context),
      _emissiveTexture(context),
      _emissiveFactor(),
      _alphaMode(),
      _alphaCutoff(),
      _doubleSided() {}

void MaterialJsonHandler::reset(
    CesiumJsonReader::IJsonHandler* pParentHandler,
    Material* pObject) {
  NamedObjectJsonHandler::reset(pParentHandler, pObject);
  this->_pObject = pObject;
}

CesiumJsonReader::IJsonHandler*
MaterialJsonHandler::readObjectKey(const std::string_view& str) {
  assert(this->_pObject);
  return this->readObjectKeyMaterial(Material::TypeName, str, *this->_pObject);
}

CesiumJsonReader::IJsonHandler* MaterialJsonHandler::readObjectKeyMaterial(
    const std::string& objectType,
    const std::string_view& str,
    Material& o) {
  using namespace std::string_literals;

  if ("pbrMetallicRoughness"s == str)
    return property(
        "pbrMetallicRoughness",
        this->_pbrMetallicRoughness,
        o.pbrMetallicRoughness);
  if ("normalTexture"s == str)
    return property("normalTexture", this->_normalTexture, o.normalTexture);
  if ("occlusionTexture"s == str)
    return property(
        "occlusionTexture",
        this->_occlusionTexture,
        o.occlusionTexture);
  if ("emissiveTexture"s == str)
    return property(
        "emissiveTexture",
        this->_emissiveTexture,
        o.emissiveTexture);
  if ("emissiveFactor"s == str)
    return property("emissiveFactor", this->_emissiveFactor, o.emissiveFactor);
  if ("alphaMode"s == str)
    return property("alphaMode", this->_alphaMode, o.alphaMode);
  if ("alphaCutoff"s == str)
    return property("alphaCutoff", this->_alphaCutoff, o.alphaCutoff);
  if ("doubleSided"s == str)
    return property("doubleSided", this->_doubleSided, o.doubleSided);

  return this->readObjectKeyNamedObject(objectType, str, *this->_pObject);
}

void MaterialJsonHandler::AlphaModeJsonHandler::reset(
    CesiumJsonReader::IJsonHandler* pParent,
    Material::AlphaMode* pEnum) {
  JsonHandler::reset(pParent);
  this->_pEnum = pEnum;
}

CesiumJsonReader::IJsonHandler*
MaterialJsonHandler::AlphaModeJsonHandler::readString(
    const std::string_view& str) {
  using namespace std::string_literals;

  assert(this->_pEnum);

  if ("OPAQUE"s == str)
    *this->_pEnum = Material::AlphaMode::OPAQUE;
  else if ("MASK"s == str)
    *this->_pEnum = Material::AlphaMode::MASK;
  else if ("BLEND"s == str)
    *this->_pEnum = Material::AlphaMode::BLEND;
  else
    return nullptr;

  return this->parent();
}
