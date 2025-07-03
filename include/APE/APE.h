#ifndef __APE_H__
#define __APE_H__

namespace APE {
  /// @brief Initialize the APE, must call before using the APE. If this fails,
  /// you shouldn't continue using the APE.
  /// @return true on success, false on failure.
  bool Initialize();

  /// @brief Deinitialize the APE and release the resources.
  void Deinitialize();
}

#endif // __APE_H__
