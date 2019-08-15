open Types;

let str = ReasonReact.string;
let str_int = number => str(string_of_int(number));

let changeName = (event, dispatch, player) => {
  switch (player) {
  | Player1Hometeam =>
    dispatch(
      ChangeNamePlayer1Hometeam(ReactEvent.Form.target(event)##value),
    )
  | Player2Hometeam =>
    dispatch(
      ChangeNamePlayer2Hometeam(ReactEvent.Form.target(event)##value),
    )
  | Player1Awayteam =>
    dispatch(
      ChangeNamePlayer1Awayteam(ReactEvent.Form.target(event)##value),
    )
  | Player2Awayteam =>
    dispatch(
      ChangeNamePlayer2Awayteam(ReactEvent.Form.target(event)##value),
    )
  };
};

[@react.component]
let make = (~state: state, ~dispatch, ~player: player) => {
  let team =
    switch (player) {
    | Player1Hometeam
    | Player2Hometeam => "Hometeam"
    | Player1Awayteam
    | Player2Awayteam => "Awayteam"
    };

  let name =
    switch (player) {
    | Player1Hometeam => state.namePlayer1Hometeam
    | Player2Hometeam => state.namePlayer2Hometeam
    | Player1Awayteam => state.namePlayer1Awayteam
    | Player2Awayteam => state.namePlayer2Awayteam
    };

  let playerString =
    switch (player) {
    | Player1Hometeam
    | Player1Awayteam => "player1"
    | Player2Hometeam
    | Player2Awayteam => "player2"
    };

  let playerStringCap = String.capitalize(playerString);
  let fullId = playerString ++ team;

  <MaterialUi_Paper>
    <form>
      <label htmlFor=fullId> {str(playerStringCap ++ team)} </label>
      <input
        value=name
        name=fullId
        onChange={event => changeName(event, dispatch, player)}
      />
      <input type_="file" accept="image/*" />
    </form>
  </MaterialUi_Paper>;
};
