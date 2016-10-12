<include src="include/header"/>

<a href="/admin/course/new/{$session['token']}" class="button right">Nouveau cours</a>
<table class="table">
	<thead>
		<tr>
			<th class="matricule">Id</th>
			<th>Nom</th>
			<th class="action">Actions</th>
		<tr>
	</thead>
	<tbody>
		<foreach loop="$courses as $data">
			<tr>
				<td>{$data['id']}</td>
				<td>{$data['name']}</td>
				<td class="action">
					<a href="/admin/course/edit/{$data['id']}/{$session['token']}"><span class="fa fa-pencil"></span></a>
					<a href="/admin/course/delete/{$data['id']}/{$session['token']}"><span class="fa fa-times"></span></a>
				</td>
			</tr>
		</foreach>
	<tbody>
</table>

<include src="include/footer"/>