#pragma once

#include <string>

namespace CesiumMetadata {
class PropertyView;

class Metadata {
public:
  virtual ~Metadata() noexcept = default;

  virtual PropertyView* getProperty(const std::string& propertyName) = 0;

  virtual const PropertyView* getProperty(const std::string& propertyName) const = 0;
};
}