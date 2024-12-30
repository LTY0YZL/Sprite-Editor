/**
 * Author: Yang Hong
 * Date: 11/13/2024
 *
 * The Sprite class provides a way to handle and manipulate a sequence of QPixmap frames for animations.
 * It allows frames to be added, removed, saved, and loaded from JSON files.
**/
#include "sprite.h"

//Default constructor for Sprite class.
Sprite::Sprite() {

}

//Constructor that loads sprite data from a JSON file.
Sprite::Sprite(const QString &filePath) {
    loadFromJson(filePath);
}

//Adds a new empty frame with the specified width and height.
//The frame is initialized with transparency.
void Sprite::addFrame(int inputWidth, int inputHeight) {
    spriteWidth = inputWidth;
    spriteHeight = inputHeight;
    QPixmap newFrame(spriteWidth, spriteHeight);
    newFrame.fill(Qt::transparent);
    frames.push_back(newFrame);
}

//Adds an existing QPixmap as a frame to the sprite.
void Sprite::addFrame(const QPixmap& pixmap) {
    if (pixmap.isNull()) {
        return;
    }
    frames.push_back(pixmap);
}

//Removes a frame at a given index.
void Sprite::removeFrame(int index) {
    if (index >= 0 && index < static_cast<int>(frames.size())) {
        frames.erase(frames.begin() + index);
    }
}

//Returns the total number of frames in the sprite.
int Sprite::frameCount() const {
    return frames.size();
}

//Retrieves a frame by its index.
QPixmap& Sprite::getFrame(int index) {
    if (index >= 0 && index < static_cast<int>(frames.size())) {
        return frames[index];
    }
    else {
        throw std::out_of_range("Index out of range");
    }
}

//Saves the sprite data, including frame images, to a JSON file.
void Sprite::saveToJson(const QString &filePath) const {
    QJsonObject json;
    json["spriteWidth"] = spriteWidth;
    json["spriteHeight"] = spriteHeight;

    QJsonArray framesArray;
    for (const QPixmap &frame : frames) {
        QJsonObject frameObject;
        QByteArray byteArray;
        QBuffer buffer(&byteArray);
        buffer.open(QIODevice::WriteOnly);
        frame.save(&buffer, "PNG");
        frameObject["data"] = QString::fromLatin1(byteArray.toBase64());
        framesArray.append(frameObject);
    }
    json["frames"] = framesArray;

    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly)) {
        qWarning("Couldn't open file for writing.");
        return;
    }

    QJsonDocument doc(json);
    file.write(doc.toJson());
}

//Loads sprite data, including frame images, from a JSON file.
bool Sprite::loadFromJson(const QString &filePath){
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly)) {
        qWarning("Could not open file for reading.");
        return false;
    }
    QByteArray fileData = file.readAll();
    QJsonDocument doc(QJsonDocument::fromJson(fileData));
    if (doc.isNull() || !doc.isObject()) {
        qWarning("Invalid JSON file.");
        return false;
    }
    QJsonObject json = doc.object();
    if (!json.contains("spriteWidth") || !json.contains("spriteHeight") || !json.contains("frames")) {
        qWarning("Missing necessary fields in JSON file.");
        return false;
    }

    spriteWidth = json["spriteWidth"].toInt();
    spriteHeight = json["spriteHeight"].toInt();

    frames.clear();
    QJsonArray framesArray = json["frames"].toArray();
    for (const QJsonValue &frameValue : framesArray) {
        QJsonObject frameObject = frameValue.toObject();
        QByteArray byteArray = QByteArray::fromBase64(frameObject["data"].toString().toLatin1());
        QPixmap pixmap;
        if (!pixmap.loadFromData(byteArray, "PNG")) {
            qWarning("Failed to load frame data.");
            return false;
        }
        frames.push_back(pixmap);
    }

    return true;
}

