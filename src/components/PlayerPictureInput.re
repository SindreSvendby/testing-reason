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
let make = (~state: state, ~dispatch, ~player: players) => {
  let (picture, setPicture) = React.useState(() => "");
  let info = PlayerInfo.info(~playerType=player, ~state=state)

  let capturePicture = event => {
    let fileList = ReactEvent.Form.target(event)##files;
    let file: option(Webapi.File.t) = fileFromFileList(fileList);
    switch (file) {
    | Some(file) =>
      let url = Webapi.Url.createObjectURL(file);
      setPicture(_ => url);
    | None => Js.log("Error: Did not get file from the webapi")
    };
  };

  let nameh5 = <MaterialUi_Typography variant=`H5>info.player.name </MaterialUi_Typography>;

  <div>
    <MaterialUi_Grid container=true justify=`Center alignItems=`Center>
      <Avatar picture playerInfo=info />
    </MaterialUi_Grid>
    <MaterialUi_Grid  container=true justify=`Center alignItems=`Center>
       <MaterialUi_Chip
        size=`Medium
        variant=`Outlined
        label=nameh5
        avatar={(<MaterialUi_Avatar 
        style={ReactDOMRe.Style.make(
          ~background=info.player.jersey.color,
          ~color="white",
          (),
        )}>
          {str_int(info.player.jersey.number)}
            </MaterialUi_Avatar>)}
        />
    </MaterialUi_Grid>
     
   
    // <input
    //   onChange=capturePicture
    //   id={info.playerString ++ "Cam111"}
    //   type_="file"
    //   accept="image/*"
    // />
  </div>;
};
