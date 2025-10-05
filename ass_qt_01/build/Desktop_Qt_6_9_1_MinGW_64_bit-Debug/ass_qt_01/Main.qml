import QtQuick
import QtQuick.Layouts
import QtQuick.Controls 2.15
import Customimage 1.0
import MusicLoader 1.0


Window {
    id: root
    width: 640
    height: 480
    visible: true
    title: qsTr("Music Player")
    Rectangle {
           anchors.fill: parent
           gradient: Gradient {
               GradientStop { position: 0.0; color: "#0A0F1C" }  // xanh đen
               GradientStop { position: 1.0; color: "#1C2235" }  // xanh tím than
           }
       }
    MusicLoader {
        id: musicLoader
        onCoverArtChanged: {
            imgMusicImage.setImage(musicLoader.coverArt)
            console.log("Cover art changed to: " + musicLoader.coverArt)
        }

    }

    Row {
        anchors.fill: parent
        spacing: 0

        Rectangle {
            width: parent.width * 0.4
            height: parent.height
            color: "#0A0F1C"
            border.width: 2
            border.color: "blue"
            // nền
            // Image {
            //     id: image_music
            //     source: musicLoader.coverArt !== ""
            //                 ? "file:///" + musicLoader.coverArt
            //                 : "qrc:/images/default_cover.png"
            //         fillMode: Image.PreserveAspectFit
            //            width: parent.width * 0.9
            //            height: parent.width * 0.9
            //            smooth: true
            //            anchors.centerIn: parent
            // }
            Customimage {
                id: imgMusicImage
                // height: width
                // width: parent.width/3.2
                // anchors.right: parent.right
                // anchors.top: parent.top
                // anchors.topMargin: 20
                // anchors.rightMargin: 20
                width: parent.width * 0.9
                                height: parent.width * 0.9
                                  smooth: true
                                     anchors.centerIn: parent
            }
        }

        Rectangle {
            width: parent.width * 0.6
            height: parent.height
            color: "#1C2235"
            border.width: 2
            border.color: "green"

            ColumnLayout {
                anchors.fill: parent
                anchors.margins: 16
                anchors.leftMargin: 16
                anchors.rightMargin: 16
                anchors.topMargin: 16
                anchors.bottomMargin: 16
                spacing: 12


                RowLayout {
                    Layout.fillWidth: true
                    spacing: 10

                    Rectangle { width: 24; height: 24; color: "transparent"; opacity: 0 }
                    Item { Layout.fillWidth: true }

                    Rectangle {
                        width: 24; height: 24; color: "transparent"
                        Image { source: "qrc:/Icon/autoplay.svg"; width: 24; height: 24; fillMode: Image.PreserveAspectFit }
                    }
                    // Rectangle {
                    //     width: 24; height: 24; color: "transparent"
                    //     Image { /*source: "qrc:/Icon/volume.svg";*/ width: 24; height: 24;
                    //     source: volumeSlider.value <= 0 ? "qrc:/Icon/mute.svg" : "qrc:/Icon/volume.svg"
                    //     fillMode: Image.PreserveAspectFit }
                    // }
                    Rectangle {
                            width: 24
                            height: 24
                            color: "transparent"

                            Image {
                                id: volumeIcon
                                source: volumeSlider.value <= 0 ? "qrc:/Icon/mute.svg" : "qrc:/Icon/volume.svg"
                                width: 24
                                height: 24
                                fillMode: Image.PreserveAspectFit
                            }

                            MouseArea {
                                anchors.fill: parent
                                cursorShape: Qt.PointingHandCursor
                                onClicked: {
                                    volumeSlider.visible = !volumeSlider.visible   // ẩn/hiện thanh âm lượng
                                }
                            }
                        }
                    Rectangle {
                        width: 24; height: 24; color: "transparent"
                        Image { source: "qrc:/Icon/equalizer.svg"; width: 24; height: 24; fillMode: Image.PreserveAspectFit }
                    }
                    Rectangle {
                        width: 24; height: 24; color: "transparent"
                        Image { source: "qrc:/Icon/threedotvertical.svg"; width: 24; height: 24; fillMode: Image.PreserveAspectFit }
                    }
                    Slider {
                            id: volumeSlider
                            from: 0
                            to: 100
                            value: 80
                            stepSize: 1
                            visible: false
                            Layout.preferredWidth: 120
                            onValueChanged: {
                                musicLoader.setVolume(value)
                            }
                        }
                }   /* Rectangle {
                    width: 24; height: 24; color: "transparent"
                    Image { source: "qrc:/Icon/threedotvertical.svg"; width: 24; height: 24; fillMode: Image.PreserveAspectFit }
                }*/


                Item { Layout.preferredHeight: 40 }


                ColumnLayout {
                    Layout.alignment: Qt.AlignHCenter
                    spacing: 4

                    Rectangle {
                        Layout.alignment: Qt.AlignHCenter
                        width: parent.width * 0.6
                        height: 44
                        color: "transparent"
                        radius: 6

                        Text {
                            anchors.centerIn: parent
                            text: musicLoader.title
                            font.pixelSize: 20
                            font.bold: true
                            horizontalAlignment: Text.AlignHCenter
                            color: "white"

                        }
                    }


                    Rectangle {
                        Layout.alignment: Qt.AlignHCenter
                        width: parent.width * 0.6
                        height: 24
                        color: "transparent"

                        Text {
                            anchors.centerIn: parent
                            text:  musicLoader.artist
                            font.pixelSize: 12
                            color: "#d0d0d0"
                            horizontalAlignment: Text.AlignHCenter
                        }
                    }
                    RowLayout {
                        Layout.preferredWidth: root.width * 0.5
                        Layout.preferredHeight: root.height/5
                        Layout.alignment: Qt.AlignHCenter
                        spacing: 50



                        Rectangle {
                            width: 24; height: 24; color: "transparent"
                            Image {
                                  source: "qrc:/Icon/playlist.svg"
                                width: 24; height: 24; fillMode: Image.PreserveAspectFit }
                        }


                        Rectangle {
                            width: 24; height: 24; color: "transparent"
                            Image {
                                 source: "qrc:/Icon/heart.svg"
                                width: 24; height: 24; fillMode: Image.PreserveAspectFit }
                        }


                        Rectangle {
                            width: 24; height: 24; color: "transparent"
                            Image {
                                source: "qrc:/Icon/plus.svg"
                                width: 24; height: 24; fillMode: Image.PreserveAspectFit }
                        }
                    }
                }
                Slider {
                    id: slider
                    from: 0
                    to: musicLoader.duration   // max = duration nhạc
                    value: musicLoader.position  // bind theo position
                    Layout.preferredWidth: root.width * 0.5

                    onMoved: {
                        musicLoader.setPosition(value)  // kéo slider -> tua nhạc
                    }
                }


                RowLayout {
                    Layout.preferredWidth: root.width * 0.5
                    Layout.preferredHeight: root.height/5
                    Layout.alignment: Qt.AlignHCenter
                    spacing: 50



                    Rectangle {
                        id: btnShuffle
                        width: 24; height: 24; color: "transparent"
                        Image {
                              source: "qrc:/Icon/shuffle.svg"
                            width: 24; height: 24; fillMode: Image.PreserveAspectFit }
                        MouseArea {
                                anchors.fill: parent
                                cursorShape: Qt.PointingHandCursor
                                onClicked: {
                                    musicLoader.isShuffle = !musicLoader.isShuffle
                                    console.log("Shuffle mode:", musicLoader.isShuffle)
                                }
                            }
                    }


                    Rectangle {
                        width: 24; height: 24; color: "transparent"
                        Image {
                            source: "qrc:/Icon/next-track.svg"
                            width: 24; height: 24; rotation: 180
                            fillMode: Image.PreserveAspectFit }
                        MouseArea {
                            anchors.fill: parent
                            cursorShape: Qt.PointingHandCursor
                            onClicked: {
                                 musicLoader.playPrevious()
                            }
                        }
                    }



                    Rectangle {
                        width: 24; height: 24; color: "transparent"
                        Image {
                            id: playPauseIcon
                            // source: "qrc:/Icon/pause.svg"
                            source: musicLoader.isPlaying ? "qrc:/Icon/pause.svg" : "qrc:/Icon/play.svg"
                            width: 24; height: 24; fillMode: Image.PreserveAspectFit }
                        MouseArea {
                            anchors.fill: parent
                            cursorShape: Qt.PointingHandCursor
                            onClicked: {
                                musicLoader.playOrPause()
                                // if (playPauseIcon.source === "qrc:/Icon/play.svg")
                                //                     playPauseIcon.source = "qrc:/Icon/pause.svg"
                                // else
                                //                     playPauseIcon.source = "qrc:/Icon/play.svg"
                            }
                        }
                    }


                    Rectangle {
                        width: 24; height: 24; color: "transparent"
                        Image {
                            source: "qrc:/Icon/next-track.svg"
                            width: 24; height: 24; fillMode: Image.PreserveAspectFit }
                        MouseArea {
                                        anchors.fill: parent
                                        cursorShape: Qt.PointingHandCursor
                                        onClicked: {
                                            musicLoader.playNext()
                                        }
                                    }
                    }
                    Rectangle {
                        width: 24; height: 24; color: "transparent"
                        Image {
                            source: "qrc:/Icon/plus.svg"
                            width: 24; height: 24; fillMode: Image.PreserveAspectFit }


                    }
                }




                Item { Layout.fillHeight: true }
            }
    }
}
}
