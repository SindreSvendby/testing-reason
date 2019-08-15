module MenuIcon = MscharleyBsMaterialUiIcons.Menu.Filled;

[@react.component]
let make = () => {
  <MaterialUi_AppBar position=`Static>
    <MaterialUi_Toolbar>
      <MaterialUi_IconButton edge=`Start color=`Inherit>
        <MenuIcon />
      </MaterialUi_IconButton>
      <MaterialUi_Typography variant=`H6> "News" </MaterialUi_Typography>
      <MaterialUi_Button color=`Inherit> "Login" </MaterialUi_Button>
    </MaterialUi_Toolbar>
  </MaterialUi_AppBar>;
};
