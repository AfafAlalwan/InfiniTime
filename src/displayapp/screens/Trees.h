#pragma once

#include "displayapp/apps/Apps.h"
#include "displayapp/screens/Screen.h"
#include "Symbols.h"
#include "displayapp/Controllers.h"
#include "components/prediction/PredictionController.h"
#include "predictionTask/PredictionTask.h"

namespace Pinetime {
  namespace Applications {
    class PredictionTask;

    namespace Screens {
      class Trees : public Screen {
      public:
        Trees(Controllers::PredictionController& ctrl);
        ~Trees() override;
        void ButtonPressed();

      private:
        bool buttonPressing = false;
        void StartPrediction();
        void UpdatePrediction();
        unsigned int SendDataToPredictionTask(const PredictData& msg);
        lv_obj_t* btnPredict;
        lv_obj_t* lblPrediction;
        lv_task_t* predictionTask;

        Controllers::PredictionController& controller;

      };
    }
    
    template <>
    struct AppTraits<Apps::Trees> {
      static constexpr Apps app = Apps::Trees;
      static constexpr const char* icon = Screens::Symbols::cloud; // set Tree Icon
      static Screens::Screen* Create(AppControllers& controllers) {
        return new Screens::Trees(controllers.predictionController);
      }
    };
  }
}