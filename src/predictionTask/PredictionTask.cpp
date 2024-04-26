#include "predictionTask/PredictionTask.h"
#include <nrf_log.h>
#include <components/prediction/PredictionController.h>

using namespace Pinetime::Applications;

QueueHandle_t PredictionTask::resultQueue;

PredictionTask::PredictionTask(Controllers::PredictionController& controller)
  : controller(controller) {
}

void PredictionTask::Start() {
  messageQueue = xQueueCreate(10, 1); //sizeof(PredictData)
  resultQueue = xQueueCreate(10, 1);
  controller.SetPredictionTask(this);
  if (pdPASS != xTaskCreate(PredictionTask::Predict, "Prediction", 500, this, 0, &taskHandle)) {
    APP_ERROR_HANDLER(NRF_ERROR_NO_MEM);
  }
}

void PredictionTask::Predict(void* instance) {
  auto* app = static_cast<PredictionTask*>(instance);
    PredictData msg;
    if (xQueueReceive(app->messageQueue, &msg, portMAX_DELAY)) {
        unsigned int result = app->tree.StandardIfTree_predict(msg.data);
        xQueueSend(resultQueue, &result, portMAX_DELAY);
    }
}


void PredictionTask::PushMessage(PredictData msg) {
  BaseType_t xHigherPriorityTaskWoken = pdFALSE;
  xQueueSendFromISR(messageQueue, &msg, &xHigherPriorityTaskWoken);
  portYIELD_FROM_ISR(xHigherPriorityTaskWoken); 
}

