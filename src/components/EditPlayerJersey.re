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
  <React.Fragment> <ReactColor /> </React.Fragment>;
};