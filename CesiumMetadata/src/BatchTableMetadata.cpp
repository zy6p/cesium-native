#include "CesiumMetadata/BatchTableMetadata.h"
#include "CesiumMetadata/TileFormatJsonPropertyView.h"
#include "CesiumUtility/JsonValue.h"
#include <rapidjson/reader.h>
#include <rapidjson/document.h>
#include <map>
#include <stack>

namespace {
enum class JsonType { 
  None,
  ArrayType,
  ObjectType,
};

class MetadataJsonHandler : public rapidjson::BaseReaderHandler<rapidjson::UTF8<>, MetadataJsonHandler>  {
public:
  MetadataJsonHandler() 
      : type{JsonType::None}, _currentHandler{nullptr}
  {}

  bool Null() { 
    if (_currentHandler) {
      return _currentHandler->Null();
    }

    switch (type) {
    case JsonType::ArrayType:
      vector.emplace_back(std::nullptr_t{});
      break;
    case JsonType::ObjectType:
      object.insert({key, CesiumUtility::JsonValue(std::nullptr_t{})});
      break;
    default:
      break;
    }

    return true;
  }

  bool Bool(bool b) { 
    if (_currentHandler) {
      return _currentHandler->Bool(b);
    }

    switch (type) {
    case JsonType::ArrayType:
      vector.emplace_back(b);
      break;
    case JsonType::ObjectType:
      object.insert({key, CesiumUtility::JsonValue(b)});
      break;
    default:
      break;
    }

    return true;
  }

  bool Int(int i) { 
    if (_currentHandler) {
      return _currentHandler->Int(i);
    }

    switch (type) {
    case JsonType::ArrayType:
      vector.emplace_back(i);
      break;
    case JsonType::ObjectType:
      object.insert({key, CesiumUtility::JsonValue(i)});
      break;
    default:
      break;
    }

    return true;
  }

  bool Uint(unsigned i) { 
    if (_currentHandler) {
      return _currentHandler->Uint(i);
    }

    switch (type) {
    case JsonType::ArrayType:
      vector.emplace_back(i);
      break;
    case JsonType::ObjectType:
      object.insert({key, CesiumUtility::JsonValue(i)});
      break;
    default:
      break;
    }

    return true;
  }

  bool Int64(int64_t i) { 
    if (_currentHandler) {
      return _currentHandler->Int64(i);
    }

    switch (type) {
    case JsonType::ArrayType:
      vector.emplace_back(i);
      break;
    case JsonType::ObjectType:
      object.insert({key, CesiumUtility::JsonValue(i)});
      break;
    default:
      break;
    }

    return true;
  }

  bool Uint64(uint64_t i) { 
    if (_currentHandler) {
      return _currentHandler->Uint64(i);
    }

    switch (type) {
    case JsonType::ArrayType:
      vector.emplace_back(i);
      break;
    case JsonType::ObjectType:
      object.insert({key, CesiumUtility::JsonValue(i)});
      break;
    default:
      break;
    }

    return true;
  }

  bool Double(double d) { 
    if (_currentHandler) {
      return _currentHandler->Double(d);
    }

    switch (type) {
    case JsonType::ArrayType:
      vector.emplace_back(d);
      break;
    case JsonType::ObjectType:
      object.insert({key, CesiumUtility::JsonValue(d)});
      break;
    default:
      break;
    }

    return true;
  }

  bool RawNumber(const Ch* str, rapidjson::SizeType length, bool copy) {
    if (_currentHandler) {
      return _currentHandler->RawNumber(str, length, copy);
    }

    switch (type) {
    case JsonType::ArrayType:
      vector.emplace_back(std::string(str, length));
      break;
    case JsonType::ObjectType:
      object.insert({key, CesiumUtility::JsonValue(std::string(str, length))});
      break;
    default:
      break;
    }

    return true;
  }

  bool String(const Ch* str, rapidjson::SizeType length, bool copy) {
    if (_currentHandler) {
      return _currentHandler->RawNumber(str, length, copy);
    }

    switch (type) {
    case JsonType::ArrayType:
      vector.emplace_back(std::string(str, length));
      break;
    case JsonType::ObjectType:
      object.insert({key, CesiumUtility::JsonValue(std::string(str, length))});
      break;
    default:
      break;
    }

    return true;
  }

  bool StartObject() { 
    _currentHandler = &_stacks.emplace(JsonType::ObjectType);
    return true;
  }

  bool Key(const Ch* str, rapidjson::SizeType length, bool /*copy*/) {
    key = std::string(str, length);
    return true;
  }

  bool EndObject(rapidjson::SizeType memberCount) { 
    if (_currentHandler) {
      switch (_currentHandler->type) {
		case JsonType::ArrayType:
          vector.emplace_back(std::move(_currentHandler->vector));
		  break;
		case JsonType::ObjectType:
		  object.insert(
			  {key,
			   CesiumUtility::JsonValue(
				   std::move(_currentHandler->object))});
		  break;
		default:
		  break;
      }
      _currentHandler = nullptr;
      _stacks.pop();
    }
    return true;
  }

  bool StartArray() { 
    _currentHandler = &_stacks.emplace(JsonType::ArrayType);
    return true;
  }

  bool EndArray(rapidjson::SizeType elementCount) { 
    if (_currentHandler) {
      switch (_currentHandler->type) {
		case JsonType::ArrayType:
          vector.emplace_back(std::move(_currentHandler->vector));
		  break;
		case JsonType::ObjectType:
		  object.insert(
			  {key,
			   CesiumUtility::JsonValue(
				   std::move(_currentHandler->object))});
		  break;
		default:
		  break;
      }
      _currentHandler = nullptr;
      _stacks.pop();
    }
    return true;
  }

  JsonType type;
  std::string key;
  std::map<std::string, CesiumUtility::JsonValue> object;
  std::vector<CesiumUtility::JsonValue> vector;

private:
  MetadataJsonHandler(JsonType t) 
      : type{t}, _currentHandler{nullptr}
  {}

  MetadataJsonHandler* _currentHandler;
  std::stack<MetadataJsonHandler> _stacks;
};
}

namespace CesiumMetadata {
BatchTableMetadata::BatchTableMetadata(
    std::map<std::string, std::unique_ptr<PropertyView>> properties) 
    : _properties{std::move(properties)} 
{}

PropertyView* BatchTableMetadata::getProperty(const std::string& propertyName) {
  auto propertyIter = this->_properties.find(propertyName);
  if (propertyIter == this->_properties.end()) {
    return nullptr;
  }

  return propertyIter->second.get();
}

const PropertyView*
BatchTableMetadata::getProperty(const std::string& propertyName) const {
  auto propertyIter = this->_properties.find(propertyName);
  if (propertyIter == this->_properties.end()) {
    return nullptr;
  }

  return propertyIter->second.get();
}

std::unique_ptr<BatchTableMetadata> BatchTableMetadata::create(
    size_t batchLength,
    const gsl::span<const std::byte>& batchTableJsonData,
    const gsl::span<const std::byte>& batchTableBinaryData) 
{
  MetadataJsonHandler jsonHandler;
  rapidjson::Reader reader;
  rapidjson::MemoryStream ms(
      reinterpret_cast<const char*>(batchTableJsonData.data()),
      batchTableJsonData.size() * sizeof(rapidjson::UTF8<>::Ch));
  rapidjson::EncodedInputStream<rapidjson::UTF8<>, rapidjson::MemoryStream> is(ms);
  reader.Parse(is, jsonHandler);
  if (jsonHandler.type != JsonType::ObjectType) {
    // TODO: report error
    return nullptr;
  }

  std::map<std::string, std::unique_ptr<PropertyView>> propertyViews;
  for (const auto& pair : jsonHandler.object) {
    if (pair.second.isArray()) {
      // add json properties
      const auto& data = pair.second.getArray();
      if (data.size() != batchLength) {
        // TODO: report error
        continue;
      }

      propertyViews.insert(
          {pair.first,
           std::make_unique<TileFormatJsonPropertyView>(
               pair.second.getArray())});
    } else {
      // add binary properties
    }
  }

  return std::unique_ptr<BatchTableMetadata>(
      new BatchTableMetadata(std::move(propertyViews)));
}
}