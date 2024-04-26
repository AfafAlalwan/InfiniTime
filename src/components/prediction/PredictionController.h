#pragma once

#include <cstdint>

namespace Pinetime {
  namespace Applications {
    class PredictionTask;
    struct PredictData;
  } 

  namespace System {
    class SystemTask;
  }

  namespace Controllers {
    class PredictionController {
    public:
      PredictionController() = default;
      void Start(Pinetime::Applications::PredictData msg);
      void SetPredictionTask(Applications::PredictionTask* task);

      unsigned int getResult() const {
        return result;
      }

      void setResult(unsigned int newResult) {
        result = newResult;
      }

    private:
      Applications::PredictionTask* task = nullptr;
      unsigned int result;

    };
  }
}