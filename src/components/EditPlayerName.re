open Types;

let str = ReasonReact.string;
let str_int = number => str(string_of_int(number));

let changeName = (~event: ReactEvent.Form.t, ~dispatch, ~player: players) => {
  let name = ReactEvent.Form.target(event)##value;
  if (name != "") {
    dispatch(ChangeName(ReactEvent.Form.target(event)##value, player));
  };
};

[@react.component]
let make = (~state: state, ~dispatch, ~player: players) => {
  let info = PlayerInfo.info(~state, ~playerType=player);
  let value = info.player.name == info.playerString ? "" : info.player.name;
  <React.Fragment>
    <MaterialUi_TextField
      onChange={event => {
        Js.log2("CHANGE:", player);
        changeName(~event, ~dispatch, ~player);
      }}
      placeholder={info.player.name}
      label={"Name"->ReasonReact.string}
      value
      margin=`Normal
    />
    <MaterialUi_Button onClick={_event => dispatch(Edit(Picture))}>
      "Next"->ReasonReact.string
    </MaterialUi_Button>
  </React.Fragment>;
};

