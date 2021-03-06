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
let make = (~playerInfo: playerInfo, ~picture: string) => {
  let nameh5 =
    <MaterialUi_Typography variant=`H5>
      {playerInfo.player.name}
    </MaterialUi_Typography>;

  let chip =
    <MaterialUi_Grid container=true justify=`Center alignItems=`Center>
      <MaterialUi_Chip
        size=`Medium
        variant=`Outlined
        label=nameh5
        avatar={
          <MaterialUi_Avatar
            style={ReactDOMRe.Style.make(
              ~background=playerInfo.player.jersey.color,
              ~color="white",
              (),
            )}>
            {str_int(playerInfo.player.jersey.number)}
          </MaterialUi_Avatar>
        }
      />
    </MaterialUi_Grid>;

  let avatar =
    switch (picture) {
    | "" =>
      <MaterialUi_Avatar
        style={ReactDOMRe.Style.make(
          ~margin="20px",
          ~width="200px",
          ~height="200px",
          ~background=playerInfo.player.jersey.color,
          (),
        )}>
        <MaterialUi_Typography variant=`H1>
          {str_int(playerInfo.player.jersey.number)}
        </MaterialUi_Typography>
      </MaterialUi_Avatar>
    | _ =>
      <MaterialUi_Avatar
        alt={playerInfo.playerString}
        src=picture
        style={ReactDOMRe.Style.make(
          ~margin="20px",
          ~width="200px",
          ~height="200px",
          (),
        )}
      />
    };

  <div>
    <MaterialUi_Grid container=true justify=`Center alignItems=`Center>
      avatar
    </MaterialUi_Grid>
    chip
  </div>;
  // <input
  //   onChange=capturePicture
  //   id={info.playerString ++ "Cam111"}
  //   type_="file"
  //   accept="image/*"
  // />
};