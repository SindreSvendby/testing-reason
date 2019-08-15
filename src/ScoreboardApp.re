open Types;

let str = ReasonReact.string;
let str_int = number => str(string_of_int(number));

[@react.component]
let make = () => {
  let (state, dispatch) =
    React.useReducer(Types.reducer, Types.initialState);
  <div>
    <AppBar />
    <MaterialUi_Grid container=true>
      <ReactSwipeableViews>
        <MaterialUi_Grid container=true>
          <MaterialUi_Grid item=true xs=V6>
            <MaterialUi_Paper>
              <div> {str_int(state.scoreH)} </div>
              <button onClick={_event => dispatch(AddPointsHometeam)}>
                {str("Add Point Hometeam")}
              </button>
            </MaterialUi_Paper>
          </MaterialUi_Grid>
          <MaterialUi_Grid item=true xs=V6>
            <MaterialUi_Paper>
              <div> {str_int(state.scoreA)} </div>
              <button onClick={_event => dispatch(AddPointsAwayteam)}>
                {str("Add Point Awayteam")}
              </button>
            </MaterialUi_Paper>
          </MaterialUi_Grid>
        </MaterialUi_Grid>
        <TeamSettingsTeam state dispatch player=Player1Hometeam />
        <TeamSettingsTeam state dispatch player=Player2Hometeam />
        <TeamSettingsTeam state dispatch player=Player1Awayteam />
        <TeamSettingsTeam state dispatch player=Player2Awayteam />
      </ReactSwipeableViews>
    </MaterialUi_Grid>
  </div>;
};
