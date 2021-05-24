#pragma once

#include <functional>
#include <string>

namespace CesiumMetadata {
class PropertyView;

class Metadata {
public:
  virtual ~Metadata() noexcept = default;

  virtual PropertyView* getProperty(const std::string& propertyName) = 0;

  virtual const PropertyView*
  getProperty(const std::string& propertyName) const = 0;

  virtual void forEachProperty(
      std::function<
          void(const std::string& name, PropertyView& propertyView)>) = 0;

  virtual void forEachProperty(
      std::function<
          void(const std::string& name, const PropertyView& propertyView)>)
      const = 0;
};
} // namespace CesiumMetadata