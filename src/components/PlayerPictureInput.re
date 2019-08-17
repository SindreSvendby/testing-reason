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
let make = (~state: state, ~dispatch) => {
  let (picture, setPicture) = React.useState(() => "");

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

  <div>
    <MaterialUi_Grid container=true justify=`Center alignItems=`Center>
      <MaterialUi_Avatar
        alt=playerString
        src=picture
        style={ReactDOMRe.Style.make(
          ~margin="20px",
          ~width="200px",
          ~height="200px",
          (),
        )}
      />
    </MaterialUi_Grid>
    <input
      onChange=capturePicture
      id={playerString ++ "Cam111"}
      type_="file"
      accept="image/*"
    />
  </div>;
};
