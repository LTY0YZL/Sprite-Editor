/**
 * Author: Yang Hong
 * Date: 11/13/2024
 *
 * The Sprite class provides a way to handle and manipulate a sequence of QPixmap frames for animations.
 * It allows frames to be added, removed, saved, and loaded from JSON files.
**/
#ifndef SPRITE_H
#define SPRITE_H

#include <QPixmap>
#include <QJsonObject>
#include <QJsonArray>
#include <QString>
#include <QImage>
#include <vector>
#include <QFile>
#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonObject>
#include <QJsonArray>
#include <QBuffer>

using std::vector;

//sprite class
class Sprite
{
private:
    vector<QPixmap> frames;
    int spriteWidth;
    int spriteHeight;
public:
    Sprite();
    Sprite(const QString &filePath);                // Constructor to load from JSON

    void addFrame(int inputWidth, int inputHeight); // Add a new empty frame of specific width and height
    void removeFrame(int index);                    // Remove a frame at a specific index
    int frameCount() const;                         // Get the number of frames
    QPixmap &getFrame(int index);                   // Retrieve a frame by index
    void addFrame(const QPixmap &pixmap);           // Add an existing QPixmap as a frame
    void saveToJson(const QString &filePath) const; // Save the sprite to a JSON file
    bool loadFromJson(const QString &filePath);     // Load the sprite from a JSON file
};

#endif // SPRITE_H
