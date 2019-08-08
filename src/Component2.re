let str = ReasonReact.string;
let str_int = number => str(string_of_int(number));
/* State declaration */
type state = {
  scoreH: int,
  scoreA: int,
  namePlayer1Hometeam: string,
  namePlayer2Hometeam: string,
  namePlayer1Awayteam: string,
  namePlayer2Awayteam: string,
};

let initialState: state = {
  scoreA: 0,
  scoreH: 0,
  namePlayer1Hometeam: "",
  namePlayer2Hometeam: "",
  namePlayer1Awayteam: "",
  namePlayer2Awayteam: "",
};

/* Action declaration */
type action =
  | AddPointsHometeam
  | AddPointsAwayteam
  | ChangeNamePlayer1Hometeam(string)
  | ChangeNamePlayer2Hometeam(string)
  | ChangeNamePlayer1Awayteam(string)
  | ChangeNamePlayer2Awayteam(string);

let reducer = (state, action) => {
  Js.log(state);
  switch (action) {
  | AddPointsHometeam => {...state, scoreH: state.scoreH + 1}
  | AddPointsAwayteam => {...state, scoreA: state.scoreA + 1}
  | ChangeNamePlayer1Hometeam(value) => {
      ...state,
      namePlayer1Hometeam: value,
    }
  | ChangeNamePlayer2Hometeam(value) => {
      ...state,
      namePlayer2Hometeam: value,
    }
  | ChangeNamePlayer1Awayteam(value) => {
      ...state,
      namePlayer1Awayteam: value,
    }
  | ChangeNamePlayer2Awayteam(value) => {
      ...state,
      namePlayer2Awayteam: value,
    }
  };
};

[@react.component]
let make = () => {
  let (state, dispatch) = React.useReducer(reducer, initialState);

  <div>
    <div> {str_int(state.scoreH)} </div>
    <button onClick={_event => dispatch(AddPointsHometeam)}>
      {str("Add Point Hometeam")}
    </button>
    <div> {str_int(state.scoreA)} </div>
    <button onClick={_event => dispatch(AddPointsAwayteam)}>
      {str("Add Point Awayteam")}
    </button>
    <form>
      <label htmlFor="player1Hometeam"> {str("Player1 HomeTeam")} </label>
      <input
        name="player1Hometeam"
        onChange={event =>
          dispatch(
            ChangeNamePlayer1Hometeam(ReactEvent.Form.target(event)##value),
          )
        }
      />
    </form>
    <form>
      <label htmlFor="player2Hometeam"> {str("Player2 HomeTeam")} </label>
      <input
        name="player2Hometeam"
        onChange={event =>
          dispatch(
            ChangeNamePlayer2Awayteam(ReactEvent.Form.target(event)##value),
          )
        }
      />
    </form>
    <form>
      <label htmlFor="player1Awayteam"> {str("Player1 Awayteam")} </label>
      <input
        name="player1Awayteam"
        onChange={event =>
          dispatch(
            ChangeNamePlayer1Awayteam(ReactEvent.Form.target(event)##value),
          )
        }
      />
    </form>
    <form>
      <label htmlFor="player2Awayteam"> {str("Player2 Awayteam")} </label>
      <input
        name="player2Awayteam"
        onChange={event =>
          dispatch(
            ChangeNamePlayer2Awayteam(ReactEvent.Form.target(event)##value),
          )
        }
      />
    </form>
  </div>;
};
