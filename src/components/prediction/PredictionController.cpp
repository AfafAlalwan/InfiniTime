#include "components/prediction/PredictionController.h"
#include <predictionTask/PredictionTask.h>
#include <systemtask/SystemTask.h> 

using namespace Pinetime::Controllers;


void PredictionController::Start(Pinetime::Applications::PredictData msg) {
  if (task != nullptr) {
    task->PushMessage(msg);
  }
}

void PredictionController::SetPredictionTask(Pinetime::Applications::PredictionTask* task) {
  this->task = task;
}
