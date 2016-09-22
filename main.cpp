#include <iostream>
#include <alsa/asoundlib.h>
#include <stdlib.h>

using namespace std;

void setVolume(long volume);
string getSSID();

int main() {

    long input = 0;

    while(input >= 0){
        cout << "To set the volume, please give me an value from 0-100 or < 0 to exit" << endl;
        cin >> input;
        if(input >= 0){
            setVolume(input);
        }
    }

    return 0;
}

string getSSID(){
    return "";
}

void setVolume(long volume){
    long min, max;
    snd_mixer_t *handle;
    snd_mixer_selem_id_t *sid;
    const char *card = "default";
    const char *selem_name = "Master";

    snd_mixer_open(&handle, 0);
    snd_mixer_attach(handle, card);
    snd_mixer_selem_register(handle, NULL, NULL);
    snd_mixer_load(handle);

    snd_mixer_selem_id_alloca(&sid);
    snd_mixer_selem_id_set_index(sid, 0);
    snd_mixer_selem_id_set_name(sid, selem_name);
    snd_mixer_elem_t* elem = snd_mixer_find_selem(handle, sid);

    snd_mixer_selem_get_playback_volume_range(elem, &min, &max);
    snd_mixer_selem_set_playback_volume_all(elem, volume * max / 100);

    snd_mixer_close(handle);
}