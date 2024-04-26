#pragma once
#include <FreeRTOS.h>
#include <task.h>
#include <queue.h>
#include <components/rf/StandardIfTree.h>
#include "components/prediction/PredictionController.h"

namespace Pinetime {

  namespace Controllers {
    class PredictionController;
  } 

  namespace Applications {
    
    // Define the data structure that will be passed to the queue.
    struct PredictData {
      float data[8];
    };

    class PredictionTask {
    public:
      explicit PredictionTask(Controllers::PredictionController& controller);

      static void Predict(void* instance);
      void PushMessage(PredictData msg);
      void Start();
      static QueueHandle_t resultQueue;

    private:
      Controllers::StandardIfTree tree;
      Controllers::PredictionController& controller;

      TaskHandle_t taskHandle;
      QueueHandle_t messageQueue;
     // unsigned int result;
    };


  }
}
