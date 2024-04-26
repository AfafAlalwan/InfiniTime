#include <displayapp/screens/Trees.h>
#include <lvgl/lvgl.h>
#include <components/prediction/PredictionController.h>

using namespace Pinetime::Applications::Screens;

// This object is retrieved using the user_data pointer,
// which is assumed to be set to the Trees instance.
static void btnEventHandler(lv_obj_t* obj, lv_event_t event) {
  auto* screen = static_cast<Trees*>(obj->user_data);
  if (event == LV_EVENT_PRESSED) {
    screen->ButtonPressed();
    }
}

//constructor sets up the user interface for the screen
Trees::Trees(Pinetime::Controllers::PredictionController& ctrl) : controller(ctrl) {
// Create a "Predict" button
    btnPredict = lv_btn_create(lv_scr_act(), nullptr); // Create button on the active screen
    lv_obj_set_event_cb(btnPredict, btnEventHandler); // Set the event handler
    lv_obj_align(btnPredict, nullptr, LV_ALIGN_CENTER, 0, -50); // Align the button on the screen
    lv_obj_t* label = lv_label_create(btnPredict, nullptr); // Add a label to the button
    lv_label_set_text(label, "Predict"); // Set the button's label text

    // Create a label for predictions
    lblPrediction = lv_label_create(lv_scr_act(), nullptr); // Create label on the active screen
    lv_obj_align(lblPrediction, nullptr, LV_ALIGN_CENTER, 0, 50); // Align the label on the screen

    // Initialize the prediction task but don't start it yet
    predictionTask = nullptr;
}

Trees::~Trees() {
    if (predictionTask) {
        lv_task_del(predictionTask);
    }
    // lv_obj_del(btnPredict);
    // lv_obj_del(lblPrediction);
    lv_obj_clean(lv_scr_act());
}

void Trees::ButtonPressed() {
  if(buttonPressing)
    return;
  StartPrediction();
  buttonPressing = true;
}

void Trees::StartPrediction(){
    //  ^ call this when touch event occurs on a predict button
    // Start or restart the prediction task
    if (predictionTask) {
        lv_task_reset(predictionTask); // Reset the task if it already exists
    } else {
        // Create a new task if it doesn't exist
        predictionTask = lv_task_create([](lv_task_t* task) {
            auto* instance = static_cast<Trees*>(task->user_data); //NOT SURE ABOUT INSTANCE
            instance->UpdatePrediction();
        }, 1000, LV_TASK_PRIO_LOW, this); // Adjust the period (1000 ms) and priority as needed
    }

} 

void Trees::UpdatePrediction(){

    lv_label_set_text(lblPrediction, "Predicting...");

    // TODO: find a way to receive data from sensors
    float dummyData[8] = {1.0f, 193.0f, 50.0f, 16.0f, 375.0f, 25.9f, 0.655f, 24.0f}; 
    PredictData msg;
    for (int i = 0; i < 8; ++i) {
        msg.data[i] = dummyData[i];
    }
    unsigned int result = SendDataToPredictionTask(msg);

    // do we need to wait here(?)
    // show it on screen or return with the value 
    if(result == 0)
    {
        lv_label_set_text(lblPrediction, "No Diabetes.");
    }
    else
    {
        lv_label_set_text(lblPrediction, "Has Diabetes!");
    }


    // after prediction show result and set button pressing to false
    buttonPressing = false;
}

unsigned int Trees::SendDataToPredictionTask(const PredictData& msg) {
  // Send data to prediction task through controller
  controller.Start(msg);

  // Wait for the result (?)
//   unsigned int result;
//   if (xQueueReceive(resultQueue, &result, portMAX_DELAY) == pdPASS) {
//     return result;
//   }

  // Handle error or timeout case
  return controller.getResult(); // or some error code
}