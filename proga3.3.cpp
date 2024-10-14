#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <Windows.h>

class Content {
    char title[100];  // Название трека
    char artist[50];  // Исполнитель
    float duration;   // Продолжительность в секундах
    char format[10];  // Формат (например, MP3)

public:
    void set(char* t, char* a, float d, char* f) {
        strcpy(title, t);
        strcpy(artist, a);
        duration = d;
        strcpy(format, f);
    }
};

class AudioSettings {
    int volume;    // Уровень громкости (0 - 100)
    int balance;   // Баланс между левым и правым каналом (-50 до +50)

public:
    void set(int i, int j) {
        volume = i;
        balance = j;
    }
};

class Device {
    char deviceName[100];   // Название устройства
    int maxVolume;          // Максимальная громкость устройства
    int currentVolume;      // Текущая громкость устройства

public:
    void set(char* d, int i, int j) {
        strcpy(deviceName, d);
        maxVolume = i;
        currentVolume = j;
    }
};

class Equalizer {
    int bass;      // Уровень низких частот (-10 до +10)
    int mid;       // Уровень средних частот (-10 до +10)
    int treble;    // Уровень высоких частот (-10 до +10)

public:
    void set(int b, int m, int t) {
        bass = b;
        mid = m;
        treble = t;
    }
};

class PlaylistSettings {
    int shuffle;  // Включен ли режим случайного воспроизведения (1 — да, 0 — нет)
    int repeat;   // Включен ли режим повторного воспроизведения (1 — да, 0 — нет)

public:
    void set(int s, int r) {
        shuffle = s;
        repeat = r;
    }
};

class TrackProgress {
    float currentTime;  // Текущее время воспроизведения в секундах
    float totalTime;    // Общее время трека в секундах
    int isPlaying;      // Флаг воспроизведения (1 — воспроизводится, 0 — пауза)

public:
    void set(float c, float t, int i) {
        currentTime = c;
        totalTime = t;
        isPlaying = i;
    }
};

class Playlist {
    char name[50];  // Имя плейлиста
    Content tracks[100];  // Массив треков
    int trackCount;  // Количество треков
public:
    void set(char* n, int t) {
        strcpy(name, n);
        trackCount = t;
    }
    // Функция для добавления треков в плейлист
    void add_tracks_to_playlist(Playlist* myPlaylist) {
        strcpy(myPlaylist->name, "My Playlist");
        myPlaylist->trackCount = 2;

        // Заполняем информацию о первом треке
        strcpy(myPlaylist->tracks[0].title, "Song 1");
        strcpy(myPlaylist->tracks[0].artist, "Artist 1");
        myPlaylist->tracks[0].duration = 180.0;
        strcpy(myPlaylist->tracks[0].format, "MP3");

        // Заполняем информацию о втором треке
        strcpy(myPlaylist->tracks[1].title, "Song 2");
        strcpy(myPlaylist->tracks[1].artist, "Artist 2");
        myPlaylist->tracks[1].duration = 200.0;
        strcpy(myPlaylist->tracks[1].format, "MP3");
    }
};

class User {
    char username[50];               // Имя пользователя
    AudioSettings audioSettings;  // Настройки аудио
    Device device;               // Устройство пользователя
    Equalizer equalizer;         // Настройки эквалайзера
    char preferredCodec[10];            // Предпочтительный аудиоформат
public:
    void set(char* u, char* p) {
        strcpy(username, u);
        strcpy(preferredCodec, p);
    }
};


// Функция для заполнения информации о пользователе
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

// Функция для вывода информации о плейлисте
void print_playlist_info(struct Playlist* myPlaylist) {
    printf("Playlist: %s\n", myPlaylist->name);
    for (int i = 0; i < myPlaylist->trackCount; i++) {
        printf("Track %d: %s by %s (Duration: %.2f sec, Format: %s)\n", i + 1, myPlaylist->tracks[i].title, myPlaylist->tracks[i].artist, myPlaylist->tracks[i].duration, myPlaylist->tracks[i].format);
    }
}

// Функция для вывода информации о пользователе
void print_user_info(struct User* user) {
    printf("\nUser: %s\nPreferred Volume: %d\nDevice: %s (Current Volume: %d)\nEqualizer: Bass=%d, Mid=%d, Treble=%d\n",
        user->username, user->audioSettings.volume, user->device.deviceName, user->device.currentVolume,
        user->equalizer.bass, user->equalizer.mid, user->equalizer.treble);
}

// Функция для вывода настроек плейлиста
void print_playlist_settings(struct PlaylistSettings* settings) {
    printf("\nPlaylist Settings:\nShuffle: %s\nRepeat: %s\n",
        settings->shuffle ? "On" : "Off", settings->repeat ? "On" : "Off");
}

// Функция для вывода текущего состояния трека
void print_track_progress(struct TrackProgress* progress) {
    printf("\nTrack Progress: %.2f/%.2f sec [%s]\n",
        progress->currentTime, progress->totalTime, progress->isPlaying ? "Playing" : "Paused");
}

int main() {
    Playlist myPlaylist;
    User user;
    PlaylistSettings playlistSettings;
    TrackProgress trackProgress;

    // Добавляем треки в плейлист
    Playlist add_tracks_to_playlist(&myPlaylist);

    // Заполняем данные пользователя
    fill_user_data(&user);

    // Настройки плейлиста
    playlistSettings.shuffle = 1;
    playlistSettings.repeat = 0;

    // Прогресс трека
    trackProgress.currentTime = 60.0;
    trackProgress.totalTime = 180.0;
    trackProgress.isPlaying = 1;

    // Выводим информацию о плейлисте и пользователе
    print_playlist_info(&myPlaylist);
    print_user_info(&user);
    print_playlist_settings(&playlistSettings);
    print_track_progress(&trackProgress);

    return 0;
}
