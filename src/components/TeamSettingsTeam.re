open Types;

let str = ReasonReact.string;
let str_int = number => str(string_of_int(number));

let modalStyles =
  ReactDOMRe.Style.make(
    ~position="absolute",
    ~width="200px",
    ~backgroundColor="white",
    ~border="2px solid #000",
    ~boxShadow="grey",
    ~padding="5px",
    ~top="20%",
    ~left="20%",
    ~transform="translate(-20%, -$20%)",
    (),
  );

[@react.component]
let make = (~state: state, ~dispatch, ~player: players, ~index: int) => {
  let currentPlayer = PlayerInfo.indexToPlayer(index);
  let edit =
    switch (state.edit) {
    | EditNone => false
    | Jersey
    | Player
    | Picture => true
    };

  let editComponent =
    switch (state.edit) {
    | EditNone => <React.Fragment> ""->ReasonReact.string </React.Fragment>
    | Jersey => <EditPlayerJersey state dispatch player />
    | Player => <EditPlayerName state dispatch player />
    | Picture => <EditPlayerPicture state dispatch player />
    };

  <div>
    <MaterialUi_Modal
      open_={edit && currentPlayer == player}
      onClose={(_event, _s) => dispatch(Edit(EditNone))}>
      <div style=modalStyles> editComponent </div>
    </MaterialUi_Modal>
    <PlayerPictureInput state player />
  </div>;
  // let info = PlayerInfo.info(~playerType=player, ~state);
};