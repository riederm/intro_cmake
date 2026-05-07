#include <mosquitto.h>
#include <stdio.h>

int main(void) {
    int major, minor, revision;
    mosquitto_lib_version(&major, &minor, &revision);
    printf("libmosquitto %d.%d.%d\n", major, minor, revision);

    mosquitto_lib_init();

    struct mosquitto *client = mosquitto_new("demo-client", true, NULL);
    if (!client) {
        fprintf(stderr, "mosquitto_new failed\n");
        mosquitto_lib_cleanup();
        return 1;
    }
    printf("MQTT-Client erfolgreich angelegt.\n");

    mosquitto_destroy(client);
    mosquitto_lib_cleanup();
    return 0;
}
