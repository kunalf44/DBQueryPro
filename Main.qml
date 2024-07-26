import QtQuick
import QtQuick.VirtualKeyboard
import QtQuick.Controls
import QtQuick.Layouts
import Db
Window {
    id: window
    width: 800
    height: 480
    visible: true
    title: qsTr("Hello World")
    color: "#FAF9F6"

    Db{
        id: db
    }

    ColumnLayout{
        anchors.top: parent.top
        anchors.topMargin: 10
        anchors.left: parent.left
        anchors.leftMargin: 25
        spacing: 20

        Text{
            text:"Insert into DB"
            font.bold: true
        }

    RowLayout{
        spacing:10
        Text{
            text:"ID"
        }
        TextField{
            id: insertid
            Layout.preferredWidth: 50
            placeholderText:"id"
        }
        Text{
            text:"Name"
        }
        TextField{
            id: insertname
            placeholderText:"name"
        }
        Text{
            text:"Email"
        }
        TextField{
            id: insertemail
            Layout.preferredWidth: 200
            placeholderText:"email"
        }

        RoundButton{
            text: "  INSERT  "
            onClicked: {
                // console.log(insertid+insetname+insertemail+"dasf")
                db.insertdata(insertid.text,insertname.text,insertemail.text);
            }
        }
    }

    Text{
        text: "Delete from DB"
        font.bold:true
    }
    RowLayout{
        spacing:10
        Text{
            text:"Enter ID number to delete from table"
        }
        TextField{
            id: del_id
            placeholderText:"ID number"
        }
        RoundButton{
            text: "  DELETE  "
            onClicked: {
                db.deletedata(del_id.text)
            }
        }
    }
    RowLayout{
        spacing: 10
    RoundButton{
        text: "Display Query"
        onClicked: {
            querytxt.text=db.displaytable()
        }
    }
    RoundButton{
        text: " clear * "
        onClicked: {
          del_id.text=""
            insertid.text=""
        insertname.text=""
        insertemail.text=""
            querytxt.text="null"
        }
    }
    }
    }

    Rectangle{
        id: displayrect
        // z:2
        width: 750
        height: 230
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 25
        color: "white"
        clip: true
        Text{
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            anchors.topMargin: 10
            text: "Query Box"
        }
        ScrollView{
            width: 750
            height: 200
            anchors.top: parent.top
            anchors.topMargin: 30
            clip: true
        Text{
            id: querytxt
            anchors.top: parent.top
            anchors.topMargin: 30
            text: "null"
            wrapMode: Text.WordWrap
            elide: Text.ElideRight
        }
}
    }

}
