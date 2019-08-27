open Types;

let str = ReasonReact.string;
let str_int = number => str(string_of_int(number));

module UndoIcon = MscharleyBsMaterialUiIcons.Undo.TwoTone;

let showHomeFab = (~dispatch, ~score: int) => {
  <MaterialUi_Fab size=`Large onClick={_event => dispatch(AddPointsHometeam)}>
    {str_int(score)}
  </MaterialUi_Fab>;
};

let showUndoFab = (~dispatch) => {
  <MaterialUi_Fab size=`Medium onClick={_event => dispatch(UNDO)}>
    <UndoIcon />
  </MaterialUi_Fab>;
};

let showAwayFab = (~dispatch, ~score: int) => {
  <MaterialUi_Fab size=`Large onClick={_event => dispatch(AddPointsAwayteam)}>
    {str_int(score)}
  </MaterialUi_Fab>;
};

let setHeight = ReactDOMRe.Style.make(~height="100%", ());

let setConteinerFabStyle =
  ReactDOMRe.Style.make(~position="absolute", ~bottom="20%", ());

[@react.component]
let make = (~state: state, ~dispatch) => {
  let playerInfo = PlayerInfo.info(~playerType=Player1Hometeam, ~state);
  let homeFab = showHomeFab(~dispatch, ~score=state.scoreH);
  let awayFab = showAwayFab(~dispatch, ~score=state.scoreA);
  let undoFab = showUndoFab(~dispatch);

  <main>
    <MaterialUi_Grid alignItems=`Center container=true>
      <MaterialUi_Grid item=true xs=V12>
        <MaterialUi_Paper>
          <Avatar playerInfo picture="" />
          <MaterialUi_Grid justify=`Center alignItems=`Center container=true>
            <MaterialUi_Typography>
              {str("Player1 to serve for the first time ")}
            </MaterialUi_Typography>
          </MaterialUi_Grid>
        </MaterialUi_Paper>
      </MaterialUi_Grid>
    </MaterialUi_Grid>
    <MaterialUi_Grid
      alignItems=`Center
      style=setConteinerFabStyle
      container=true
      direction=`Column>
      <MaterialUi_Grid
        container=true
        direction=`Row
        justify=`Space_Around
        alignItems=`Stretch>
        <MaterialUi_Grid item=true>
          // {ReasonReact.string("Item 1 - Red")}
           homeFab </MaterialUi_Grid>
        <MaterialUi_Grid style=setHeight item=true>
          // {ReasonReact.string("Item 2 - Red")}
           awayFab </MaterialUi_Grid>
      </MaterialUi_Grid>
      <MaterialUi_Grid> undoFab </MaterialUi_Grid>
    </MaterialUi_Grid>
  </main>;
};