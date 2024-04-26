#pragma once

namespace Pinetime {
  namespace Controllers {
    class StandardIfTree {
    public:
        static unsigned int StandardIfTree_predict(float const pX[8]);
        static unsigned int StandardIfTree_predict0(float const pX[8]);
    };
  }
}

