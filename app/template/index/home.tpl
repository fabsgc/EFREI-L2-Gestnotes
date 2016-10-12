<include src="include/header"/>

<if condition="$session['role'] == $define['user-student']">
	<div class="home-category home-category-3">
		<ul>
			<li>
				<a href="/user">
					<i class="fa fa-user"></i>
					<span class="title">Profil</class>
				</a>
			</li>
			<li>
				<a href="/student/mark">
					<i class="fa fa-university"></i>
					<span class="title">Notes</class>
				</a>
			</li>
			<li>
				<a href="/student/course">
					<i class="fa fa-folder-open"></i>
					<span class="title">Cours</class>
				</a>
			</li>
		</ul>
	</div>
</if>
<if condition="$session['role'] == $define['user-teacher']">
	<div class="home-category">
		<ul>
			<li>
				<a href="/user">
					<i class="fa fa-user"></i>
					<span class="title">Profil</class>
				</a>
			</li>
			<li>
				<a href="/teacher/mark">
					<i class="fa fa-university"></i>
					<span class="title">Notes</class>
				</a>
			</li>
			<li>
				<a href="/teacher/course">
					<i class="fa fa-folder-open"></i>
					<span class="title">Cours</class>
				</a>
			</li>
			<li>
				<a href="/teacher/student">
					<i class="fa fa-users"></i>
					<span class="title">Élèves</class>
				</a>
			</li>
		</ul>
	</div>
</if>
<if condition="$session['role'] == $define['user-admin']">
	<div class="home-category">
		<ul>
			<li>
				<a href="/user">
					<i class="fa fa-user"></i>
					<span class="title">Profil</class>
				</a>
			</li>
			<li>
				<a href="/admin/student">
					<i class="fa fa-user-plus"></i>
					<span class="title">Élèves</class>
				</a>
			</li>
			<li>
				<a href="/admin/teacher">
					<i class="fa fa-binoculars"></i>
					<span class="title">Professeurs</class>
				</a>
			</li>
			<li>
				<a href="/admin/group">
					<i class="fa fa-users"></i>
					<span class="title">Groupes</class>
				</a>
			</li>
			<li>
				<a href="/admin/course">
					<i class="fa fa-folder-open"></i>
					<span class="title">Cours</class>
				</a>
			</li>
			<li>
				<a href="/admin/mark">
					<i class="fa fa-university"></i>
					<span class="title">Notes</class>
				</a>
			</li>
		</ul>
	</div>
</if>

<!--<form action="" method="post">
	<label>Input 1</label><input name="input1" type="text"/><br />
	<label>Input 2</label><input name="input2" type="text"/><br />
	<label>Input 3</label><input name="input3" type="text"/><br />
	<label>checkbox 1</label><input type="checkbox" name="check" value="test"/><br />
	<label>checkbox 2</label><input type="checkbox" name="check" value="test2"/><br />
	<input type="hidden" name="token" value="{$session['token']}" />
	<input type="submit" value="envoyer" />
</form>-->
<include src="include/footer"/>