#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <cstring>
#include <locale.h>
#include <Windows.h>
using namespace std;

class Content {
private:
    string title;  // Название трека
    string artist;  // Исполнитель
    float duration;   // Продолжительность в секундах
    string format;  // Формат (например, MP3)
public:
    void set(string& t, string& a, float d, string& f) {
        title = t;
        artist = a;
        duration = d;
        format = f;
    }
    void print() {
        cout << "Track: " << title << " by " << artist << " (Duration: " << duration << " sec, Format: " << format << ")\n";
    }
};

class AudioSettings {
private:
    int volume;    // Уровень громкости (0 - 100)
    int balance;   // Баланс между левым и правым каналом (-50 до +50)

public:
    void set(int& v, int& b) {
        volume = v;
        balance = b;
    }
    void print() {
        cout << "Громкость: " << volume << "\nБаланс: " << balance;
    }
};

class Device {
private:
    string deviceName;   // Название устройства
    int maxVolume;          // Максимальная громкость устройства
    int currentVolume;      // Текущая громкость устройства

public:
    void set(string& d, int& m, int& c) {
        deviceName = d;
        maxVolume = m;
        currentVolume = c;
    }
};

class Equalizer {
private:
    int bass;      // Уровень низких частот (-10 до +10)
    int mid;       // Уровень средних частот (-10 до +10)
    int treble;    // Уровень высоких частот (-10 до +10)

public:
    void set(int& b, int& m, int& t) {
        bass = b;
        mid = m;
        treble = t;
    }
};

class PlaylistSettings {
private:
    int shuffle;  // Включен ли режим случайного воспроизведения (1 — да, 0 — нет)
    int repeat;   // Включен ли режим повторного воспроизведения (1 — да, 0 — нет)

public:
    void set(int& s, int& r) {
        shuffle = s;
        repeat = r;
    }
    void print() {
        cout << "Случ воспроизведение: " << shuffle << "\nПовторное воспроизв: " << repeat;
    }
};

class TrackProgress {
private:
    float currentTime;  // Текущее время воспроизведения в секундах
    float totalTime;    // Общее время трека в секундах
    int isPlaying;      // Флаг воспроизведения (1 — воспроизводится, 0 — пауза)

public:
    void set(float& c, float& t, int& i) {
        currentTime = c;
        totalTime = t;
        isPlaying = i;
    }

    // Функция для вывода текущего состояния трека
    // void print_track_progress(struct TrackProgress* progress) {
    printf("\nTrack Progress: %.2f/%.2f sec [%s]\n",
        progress->currentTime, progress->totalTime, progress->isPlaying ? "Playing" : "Paused");
}
};

class Playlist {
private:
    PlaylistSettings* setting; //настройка плейлиста  
    Content* tracks;  // Массив треков
    int trackCount;  // Количество треков

public:
    // Функция для добавления треков в плейлист
    void add_tracks_to_playlist(int count) {
        string title;  // Название трека
        string artist;  // Исполнитель
        float duration;   // Продолжительность в секундах
        string format;  // Формат (например, MP3)
        trackCount = count;
        for (int i = 0; i <= count; i++) {
            cout << "Введите название трека";
            cin >> title;
            cout << "Введите исполнителя";
            cin >> artist;
            cout << "Продолжительность в секундах";
            cin >> duration;
            cout << "Введите название трека";
            cin >> format;
            tracks[i].set(title, artist, duration, format);
        }

    }

    // Функция для вывода информации о треках
    void print_playlist_info(struct Playlist* myPlaylist) {
        for (int i = 0; i < trackCount; i++) {
            cout << "Track " << i + 1 << ": ";
            tracks[i].print();
        }
    }

    // Функция для вывода настроек плейлиста
    void print_playlist_settings(struct PlaylistSettings* settings) {
        setting[0].print();
    }
};

class User {
private:
    string username;               // Имя пользователя
    AudioSettings audioSettings;  // Настройки аудио
    Device device;               // Устройство пользователя
    Equalizer equalizer;         // Настройки эквалайзера
    string preferredCodec;            // Предпочтительный аудиоформат
public:
    //Функция для заполнения информации о пользователе
    void fill_user_data(struct User* user) {
        strcpy(user->username, "TitovVD");
        user->audioSettings.volume = 80;
        user->audioSettings.balance = 0;
        strcpy(user->device.deviceName, "Speakers");
        user->device.maxVolume = 100;
        user->device.currentVolume = 80;
        strcpy(user->preferredCodec, "MP3");

        // Настройки эквалайзера
        user->equalizer.bass = 5;
        user->equalizer.mid = 0;
        user->equalizer.treble = 7;
    }


    // Функция для вывода информации о пользователе
    void print_user_info(struct User* user) {
        printf("\nUser: %s\nPreferred Volume: %d\nDevice: %s (Current Volume: %d)\nEqualizer: Bass=%d, Mid=%d, Treble=%d\n",
            user->username, user->audioSettings.volume, user->device.deviceName, user->device.currentVolume,
            user->equalizer.bass, user->equalizer.mid, user->equalizer.treble);
    }
};


int main() {
    Playlist myPlaylist;
    User user;
    PlaylistSettings playlistSettings;
    TrackProgress trackProgress;

    // Добавляем треки в плейлист
    Playlist add_tracks_to_playlist(myPlaylist);

    // Заполняем данные пользователя


    // Настройки плейлиста


    // Прогресс трека


    // Выводим информацию о плейлисте и пользователе


}
