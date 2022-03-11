
#include "mle/mle.h"

int main() {
    FILE* file = fopen("test.txt","a");
    mle::message message = mle::message::parentRequest();
    message.writeToFile(file);
    fclose(file);
 }