// This file was generated by generate-gltf-classes.
// DO NOT EDIT THIS FILE!
#include "AnimationJsonHandler.h"
#include "CesiumGltf/Animation.h"

#include <cassert>
#include <string>

using namespace CesiumGltf;

AnimationJsonHandler::AnimationJsonHandler(
    const ReaderContext& context) noexcept
    : NamedObjectJsonHandler(context), _channels(context), _samplers(context) {}

void AnimationJsonHandler::reset(
    CesiumJsonReader::IJsonHandler* pParentHandler,
    Animation* pObject) {
  NamedObjectJsonHandler::reset(pParentHandler, pObject);
  this->_pObject = pObject;
}

CesiumJsonReader::IJsonHandler*
AnimationJsonHandler::readObjectKey(const std::string_view& str) {
  assert(this->_pObject);
  return this->readObjectKeyAnimation(
      Animation::TypeName,
      str,
      *this->_pObject);
}

CesiumJsonReader::IJsonHandler* AnimationJsonHandler::readObjectKeyAnimation(
    const std::string& objectType,
    const std::string_view& str,
    Animation& o) {
  using namespace std::string_literals;

  if ("channels"s == str)
    return property("channels", this->_channels, o.channels);
  if ("samplers"s == str)
    return property("samplers", this->_samplers, o.samplers);

  return this->readObjectKeyNamedObject(objectType, str, *this->_pObject);
}
