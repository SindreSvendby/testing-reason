open Types;

let str = ReasonReact.string;
let str_int = number => str(string_of_int(number));

let fileFromFileList: string => option(Webapi.File.t) = [%raw
  {|
  function(files) {
    try {
    return files[0];
    } catch {
      return null
    }
  }
|}
];

[@react.component]
let make = (~state: state, ~player: players) => {
  let info = PlayerInfo.info(~playerType=player, ~state);

  let (picture, _setPicture) = React.useState(() => "");
  // let capturePicture = event => {
  //   let fileList = ReactEvent.Form.target(event)##files;
  //   let file: option(Webapi.File.t) = fileFromFileList(fileList);
  //   switch (file) {
  //   | Some(file) =>
  //     let url = Webapi.Url.createObjectURL(file);
  //     setPicture(_ => url);
  //   | None => Js.log("Error: Did not get file from the webapi")
  //   };
  // };

  <div>
    <MaterialUi_Grid container=true justify=`Center alignItems=`Center>
      <Avatar picture playerInfo=info />
    </MaterialUi_Grid>
  </div>;
  // <input
  //   onChange=capturePicture
  //   id={info.playerString ++ "Cam111"}
  //   type_="file"
  //   accept="image/*"
  // />
};